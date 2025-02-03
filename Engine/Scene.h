#pragma once

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

#include "GameObject.h"

class GameObject;

class Scene
{
public :
	explicit Scene(const std::string& _name);
	virtual ~Scene() = default;

	void Awake() const;
	void Start() const;
	void Update(float _delta_time) const;

	void PreRender() const;
	void Render(sf::RenderWindow* _window) const;
	void PostRender() const;
	void Present() const;

	void Destroy() const;

	const std::string& GetName() const;

	GameObject* CreateGameObject(const std::string& _name);
	void DestroyGameObject(const GameObject* _game_object);
	GameObject* FindGameObject(const std::string& _name) const;
	const std::vector<GameObject*>& GetGameObjects() const;

private :
	std::string name;
	std::vector<GameObject*> gameObjects;
};