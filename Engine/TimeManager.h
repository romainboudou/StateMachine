#pragma once

#include "Manager.h"

class TimeManager : public Manager
{
public:
    void Awake() override;
    void Update() override;

    static float GetDeltaTime();
    static float GetTimeSinceBeginning();

    static const sf::Clock& GetDeltaClock();
    static const sf::Clock& GetClockSinceBeginning();

private:
    static sf::Clock deltaClock;
    static sf::Clock clock;

    static float deltaTime;
};