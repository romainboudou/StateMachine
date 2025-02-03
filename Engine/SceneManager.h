#pragma once

#include "Manager.h"
#include "Scene.h"
#include "TimeManager.h"
#include "WindowManager.h"

#include <vector>

class SceneManager : public Manager
{
public :
	SceneManager();
	~SceneManager() = default;

	void Awake() override;
	void Start() override;
	void Update() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;
	void Present() override;
	void Destroy() override;

	Scene* GetScene() const { return mainScene; }

	template<typename T>
	Scene* SetScene();

private :
	std::vector<Scene*> scenes;
	Scene* mainScene = nullptr;

	WindowManager* windowManager = nullptr;
	TimeManager* timeManager = nullptr;
};

template<typename T>
Scene* SceneManager::SetScene()
{
	for (const Scene* scene : scenes)
	{
		delete scene;
	}
	scenes.clear();
	Scene* scene = static_cast<Scene*>(new T());
	scenes.push_back(scene);

	mainScene = scene;

	return scene;
}