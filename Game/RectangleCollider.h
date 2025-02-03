#pragma once

#include "Component.h"
#include <SFML/Graphics/RectangleShape.hpp>

class RectangleCollider : public Component
{
public:
    RectangleCollider() { RegisterCollider(this); }
    ~RectangleCollider() { UnregisterCollider(this); }

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
        colliderShape.setOutlineColor(sf::Color::Blue);
        _window->draw(colliderShape);
    }

    bool CheckCollision(const RectangleCollider& other) const
    {
        return bounds.intersects(other.bounds);
    }

    bool CheckCollisions() const
    {
        for (const auto& collider : colliders)
        {
            if (collider != this && collider->CheckCollision(*this))
            {
                return false;
            }
        }
        return true;
    }

    const sf::FloatRect& GetBounds() const { return bounds; }
    void SetBounds(const sf::FloatRect& _bounds) { bounds = _bounds; }

    static void RegisterCollider(RectangleCollider* collider)
    {
        colliders.push_back(collider);
    }

    static void UnregisterCollider(RectangleCollider* collider)
    {
        colliders.erase(std::remove(colliders.begin(), colliders.end(), collider), colliders.end());
    }

    static const std::vector<RectangleCollider*>& GetColliders() { return colliders; }

private:
    sf::FloatRect bounds;
    static std::vector<RectangleCollider*> colliders;
};

