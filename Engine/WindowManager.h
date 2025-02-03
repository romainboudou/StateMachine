#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Manager.h"

class WindowManager : public Manager
{
public:
    static sf::RenderWindow* GetWindow() { return mWindow; }

    void Awake() override;
    void PreRender() override;
    void Present() override;
    void Destroy() override;

private:
    static sf::RenderWindow* mWindow;
};