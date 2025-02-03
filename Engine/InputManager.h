#pragma once

#include <bitset>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "Manager.h"

class InputManager : public Manager
{
public:

    void Start() override;
    void Update() override;

    static bool GetKey(sf::Keyboard::Key _key);
    static bool GetKeyDown(sf::Keyboard::Key _key);
    static bool GetKeyUp(sf::Keyboard::Key _key);

private:
    sf::RenderWindow* mWindow = nullptr;

    static std::bitset<sf::Keyboard::Key::KeyCount> keyDown;
    static std::bitset<sf::Keyboard::Key::KeyCount> keyUp;

    static std::vector<sf::Event> events;
};