#pragma once

#include "Component.h"
#include "WindowManager.h"

class Camera : public Component
{
public :
	Camera()
	{
		renderWindow = WindowManager::GetWindow();
		view.reset(sf::FloatRect(0, 0, renderWindow->getSize().x, renderWindow->getSize().y));
	}

	void Update(float deltaTime) override
	{
		if (GameObject* owner = GetOwner())
		{
			view.setCenter(owner->GetPosition().x, owner->GetPosition().y);
		}
	}

	void PreRender() override
	{
		if (renderWindow)
		{
			renderWindow->setView(view);
		}
	}

	void SetZoom(float zoomLevel)
	{
		view.setSize(renderWindow->getSize().x / zoomLevel, renderWindow->getSize().y / zoomLevel);
	}

	float GetZoom() const
	{
		return view.getSize().x / renderWindow->getSize().x;
	}

private :
	sf::RenderWindow* renderWindow = nullptr;
	sf::View view;
};
