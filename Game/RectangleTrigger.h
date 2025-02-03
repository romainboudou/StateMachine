#pragma once

#include "Component.h"
#include "RectangleCollider.h"
#include <SFML/Graphics/RectangleShape.hpp>

class RectangleTrigger : public Component
{
public:
    RectangleTrigger() = default;

    void Update(float _delta_time) override
    {
        Maths::Vector2<float> position = GetOwner()->GetPosition();
        bounds.left = position.x - bounds.width / 2.0f;
        bounds.top = position.y - bounds.height / 2.0f;
    }

    void Render(sf::RenderWindow* _window) override
    {
        sf::RectangleShape colliderShape(sf::Vector2f(bounds.width, bounds.height));
        colliderShape.setPosition(bounds.left, bounds.top);
        colliderShape.setFillColor(sf::Color(0, 0, 0, 0));
        colliderShape.setOutlineThickness(1);
        colliderShape.setOutlineColor(sf::Color::Green);
        _window->draw(colliderShape);
    }

    bool CheckCollision(const RectangleCollider& other) const
    {
        return bounds.intersects(other.GetBounds());
    }

    const sf::FloatRect& GetBounds() const { return bounds; }
    void SetBounds(const sf::FloatRect& _bounds) { bounds = _bounds; }

private:
    sf::FloatRect bounds;
};

