#include "InputManager.h"
#include "WindowManager.h"

void InputManager::Start()
{
	mWindow = Game::GetInstance()->GetManager<WindowManager>()->GetWindow();
}

void InputManager::Update()
{
	events.clear();
	keyUp.reset();
	keyDown.reset();

	sf::Event event;
	while (mWindow->pollEvent(event))
	{
		events.push_back(event);

		if (event.type == sf::Event::Closed)
		{
			game->Quit();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code >= 0 && event.key.code < sf::Keyboard::Key::KeyCount)
			{
				keyDown.set(event.key.code);
			}
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code >= 0 && event.key.code < sf::Keyboard::Key::KeyCount)
			{
				keyUp.set(event.key.code);
			}
		}
	}
}

bool InputManager::GetKey(const sf::Keyboard::Key _key)
{
	return sf::Keyboard::isKeyPressed(_key);
}

bool InputManager::GetKeyDown(const sf::Keyboard::Key _key)
{
	return _key >= 0 && _key < sf::Keyboard::Key::KeyCount && keyDown[_key];
}

bool InputManager::GetKeyUp(const sf::Keyboard::Key _key)
{
	return _key >= 0 && _key < sf::Keyboard::Key::KeyCount && keyUp[_key];
}

std::bitset<sf::Keyboard::Key::KeyCount> InputManager::keyDown;
std::bitset<sf::Keyboard::Key::KeyCount> InputManager::keyUp;
std::vector<sf::Event> InputManager::events;
