#pragma once

#include "Component.h"
#include "InputManager.h"
#include "RectangleCollider.h"

class MovementComponent : public Component
{
public :

	void Update(const float _delta_time) override
	{
		Maths::Vector2<float> newPosition = Input(_delta_time);
		if (!CheckCollision(newPosition))
		{
			GetOwner()->SetPosition(newPosition);
		}
	}

	void SetCollider(RectangleCollider* _rectangleCollider) { rectangleCollider = _rectangleCollider; }

private :
	float speed = 200.0f;
	RectangleCollider* rectangleCollider = nullptr;

	Maths::Vector2<float> Input(const float _delta_time)
	{
		Maths::Vector2<float> position = GetOwner()->GetPosition();

		if (InputManager::GetKey(sf::Keyboard::D))
		{
			position.x += speed * _delta_time;
		}
		if (InputManager::GetKey(sf::Keyboard::Q))
		{
			position.x -= speed * _delta_time;
		}
		if (InputManager::GetKey(sf::Keyboard::Z))
		{
			position.y -= speed * _delta_time;
		}
		if (InputManager::GetKey(sf::Keyboard::S))
		{
			position.y += speed * _delta_time;
		}

		return position;
	}

	bool CheckCollision(const Maths::Vector2<float>& newPosition) const
	{
		sf::FloatRect tempBounds = rectangleCollider->GetBounds();
		tempBounds.left = newPosition.x - tempBounds.width / 2.0f;
		tempBounds.top = newPosition.y - tempBounds.height / 2.0f;

		const auto& colliders = rectangleCollider->GetColliders();
		for (const auto& collider : colliders)
		{
			if (collider != rectangleCollider && collider->GetBounds().intersects(tempBounds))
			{
				return true;
			}
		}

		return false;
	}
};