#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Component.h"

class SpaceBackground : public Component {
public:

    void Render(sf::RenderWindow* _window) override {
        for (const auto& point : points) {
            _window->draw(point);
        }
    }

    void SetMin(const sf::Vector2f& _min) { min = _min; }

    void SetMax(const sf::Vector2f& _max) { max = _max; }

    void SetNumberOfPoints(int _numberOfPoints) { numberOfPoints = _numberOfPoints; }

    void GenerateRandomPoints() 
    {
        points.clear();
        for (int i = 0; i < numberOfPoints; ++i) {
            sf::CircleShape point(2);
            point.setFillColor(sf::Color::White);

            float x = min.x + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (max.x - min.x)));
            float y = min.y + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (max.y - min.y)));
            point.setPosition(x, y);

            points.push_back(point);
        }
    }

private:
    int numberOfPoints;
    sf::Vector2f min;
    sf::Vector2f max;
    std::vector<sf::CircleShape> points;
};