#include "GameObject.h"

GameObject::~GameObject()
{
	for (Component*& component : components)
		delete component;

	components.clear();
}

std::vector<Component*>& GameObject::GetComponents()
{
	return components;
}

void GameObject::Awake() const
{
	for (Component* const& component : components)
	{
		component->Awake();
	}
}

void GameObject::Start() const
{
	for (Component* const& component : components)
	{
		component->Start();
	}
}

void GameObject::Update(const float _delta_time) const
{
	for (Component* const& component : components)
	{
		component->Update(_delta_time);
	}
}

void GameObject::PreRender() const
{
	for (Component* const& component : components)
	{
		component->PreRender();
	}
}

void GameObject::Render(sf::RenderWindow* _window) const
{
	for (Component* const& component : components)
	{
		component->Render(_window);
	}
}

void GameObject::PostRender() const
{
	for (Component* const& component : components)
	{
		component->PostRender();
	}
}

void GameObject::Present() const
{
	for (Component* const& component : components)
	{
		component->Present();
	}
}

void GameObject::Destroy() const
{
	for (Component* const& component : components)
	{
		component->Destroy();
	}
}



