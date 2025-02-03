#pragma once

#include "Game.h"

class Game;

class Manager
{
public:

    virtual void Awake() {}
    virtual void Start() {}
    virtual void Update() {}

    virtual void PreRender() {}
    virtual void Render() {}
    virtual void PostRender() {}
    virtual void Present() {}

    virtual void OnEnable() {}
    virtual void OnDisable() {}

    virtual void Destroy() {}

    Game* game = nullptr;
};