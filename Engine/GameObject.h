#pragma once
#include <string>
#include <vector>

#include "Component.h"
#include "Scene.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Maths/Vector2.h"

class Component;
class Scene;
class FriendlySquare;
class EntityStateMachine;

class GameObject
{
public:
	GameObject() = default;
	~GameObject();

	std::string GetName() const { return name; }
	Maths::Vector2<float> GetPosition() const { return position; }
	float GetRotation() const { return rotation; }
	Maths::Vector2<float> GetScale() const { return scale; }

	void SetName(const std::string& _name) { name = _name; }
	void SetPosition(const Maths::Vector2<float>& _position) { position = _position; }
	void SetRotation(const float _rotation) { rotation = _rotation; }
	void SetScale(const Maths::Vector2<float>& _scale) { scale = _scale; }

	std::vector<Component*>& GetComponents();

	template<typename T>
	T* CreateComponent();

	template<typename T>
	T* CreateState(FriendlySquare* _entity, EntityStateMachine* _entityStateMachine);

	template<typename T>
	T* GetComponent();

	void Awake() const;
	void Start() const;
	void Update(float _delta_time) const;

	void PreRender() const;
	void Render(sf::RenderWindow* _window) const;
	void PostRender() const;

	void Present() const;

	void Destroy() const;

	Scene* GetOwner() const { return owner; }
	void SetOwner(Scene* _owner) { owner = _owner; }

private :
	std::string name;
	std::vector<Component*> components;
	Scene* owner = nullptr;

	Maths::Vector2<float> position = Maths::Vector2f::Zero;
	float rotation = 0.0f;
	Maths::Vector2<float> scale = Maths::Vector2f::One;
};

template<typename T>
T* GameObject::CreateComponent()
{
	T* component = new T();
	component->SetOwner(this);
	components.push_back(component);
	return component;
}

template<typename T>
T* GameObject::CreateState(FriendlySquare* _entity, EntityStateMachine* _entityStateMachine)
{
	T* component = new T(_entity, _entityStateMachine);
	component->SetOwner(this);
	components.push_back(component);
	return component;
}

template<typename T>
T* GameObject::GetComponent()
{
	for (Component* component : components)
	{
		T* result = dynamic_cast<T*>(component);
		if (result != nullptr)
			return result;
	}

	return nullptr;
}