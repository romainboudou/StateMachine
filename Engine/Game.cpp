#include "Game.h"

#include "WindowManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "SceneManager.h"

Game* Game::instance = nullptr;

Game* Game::GetInstance()
{
    if (instance == nullptr)
        instance = new Game();

    return instance;
}

void Game::Init()
{
    CreateManager<WindowManager>();
    CreateManager<InputManager>();
    CreateManager<TimeManager>();
    CreateManager<SceneManager>();

    cout << "Launch Game" << "\n";
    for (auto& manager : managers)
    {
        manager->Awake();
    }
}

void Game::Run()
{
    for (auto& manager : managers)
    {
        manager->Start();
    }

    while (!shouldQuit)
    {
        for (auto& manager : managers)
        {
            manager->Update();
        }
        for (auto& manager : managers)
        {
            manager->PreRender();
        }
        for (auto& manager : managers)
        {
            manager->Render();
        }
        for (auto& manager : managers)
        {
            manager->PostRender();
        }
        for (auto& manager : managers)
        {
            manager->Present();
        }
    }

    for (auto& manager : managers)
    {
        manager->Destroy();
    }
}