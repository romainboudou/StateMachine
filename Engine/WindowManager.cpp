#include "WindowManager.h"

void WindowManager::Awake()
{
    mWindow = new sf::RenderWindow(sf::VideoMode(600, 600), "SFML Engine");
}

void WindowManager::PreRender()
{
    mWindow->clear(sf::Color::Black);
}

void WindowManager::Present()
{
    mWindow->display();
}

void WindowManager::Destroy()
{
    mWindow->close();
}

sf::RenderWindow* WindowManager::mWindow = nullptr;