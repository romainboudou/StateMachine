#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Manager.h"

using std::cout;

class Manager;

class Game {
public:
    static Game* GetInstance();

    void Init();
    void Run();
    void Quit() { shouldQuit = true; };

    template<class T>
    T* CreateManager();

    template<class T>
    T* GetManager();

private:
    static Game* instance;
    std::vector<Manager*> managers;
    bool shouldQuit = false;
};

template<class T>
T* Game::CreateManager()
{
    T* manager = new T();
    manager->game = this;
    managers.push_back(manager);
    return manager;
}

template<class T>
T* Game::GetManager()
{
    for (Manager*& manager : managers)
    {
        T* manager_cast = dynamic_cast<T*>(manager);
        if (manager_cast)
        {
            return manager_cast;
        }
    }
    return nullptr;
}
