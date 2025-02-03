#include "SceneManager.h"
#include "Game.h"

SceneManager::SceneManager() : Manager()
{
	Scene* main_scene = new Scene("MainScene");
	scenes.push_back(main_scene);
	mainScene = main_scene;
}

void SceneManager::Start()
{
	timeManager = game->GetManager<TimeManager>();
	windowManager = game->GetManager<WindowManager>();
}

void SceneManager::Render()
{
	for (const Scene* scene : scenes)
	{
		scene->Render(windowManager->GetWindow());
	}
}

void SceneManager::Update()
{
	for (const Scene* scene : scenes)
	{
		scene->Update(timeManager->GetDeltaTime());
	}
}

void SceneManager::Awake()
{
	for (const Scene* scene : scenes)
	{
		scene->Awake();
	}
}

void SceneManager::Destroy()
{
	for (const Scene* scene : scenes)
	{
		scene->Destroy();
	}
}

void SceneManager::PostRender()
{
	for (const Scene* scene : scenes)
	{
		scene->PostRender();
	}
}

void SceneManager::PreRender()
{
	for (const Scene* scene : scenes)
	{
		scene->PreRender();
	}
}

void SceneManager::Present()
{
	for (const Scene* scene : scenes)
	{
		scene->Present();
	}
}

