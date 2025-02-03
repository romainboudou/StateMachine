#include "TimeManager.h"

void TimeManager::Awake()
{
    deltaClock.restart();
    clock.restart();
}

void TimeManager::Update()
{
    const sf::Time delta = deltaClock.restart();
    deltaTime = delta.asSeconds();
}

float TimeManager::GetDeltaTime()
{
    return deltaTime;
}

float TimeManager::GetTimeSinceBeginning()
{
    return clock.getElapsedTime().asSeconds();
}

const sf::Clock& TimeManager::GetDeltaClock()
{
    return deltaClock;
}

const sf::Clock& TimeManager::GetClockSinceBeginning()
{
    return clock;
}

sf::Clock TimeManager::deltaClock;
sf::Clock TimeManager::clock;
float TimeManager::deltaTime = 0.0f;