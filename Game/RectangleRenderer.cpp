#include "RectangleRenderer.h"
#include <iostream>

#include "SFML/Graphics/Shape.hpp"

RectangleRenderer::RectangleRenderer()
{
	shape = new sf::RectangleShape();
}

RectangleRenderer::~RectangleRenderer()
{
	delete shape;
	shape = nullptr;
}

void RectangleRenderer::Render(sf::RenderWindow* _window)
{
	const GameObject* owner = GetOwner();

	const Maths::Vector2<float> position = owner->GetPosition();
	shape->setPosition(position.x, position.y);
	shape->setRotation(owner->GetRotation());
	shape->setSize(static_cast<sf::Vector2f>(owner->GetScale() * size));

	shape->setOrigin(origin.x, origin.y);

	shape->setFillColor(color);

	_window->draw(*shape);
}