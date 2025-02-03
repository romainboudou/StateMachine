#include "Game.h"
#include "SceneManager.h"
#include "MainScene.h"

int main()
{
    Game* game = Game::GetInstance();
    game->Init();

    SceneManager* sceneManager = game->GetManager<SceneManager>();
    sceneManager->SetScene<MainScene>();

    game->Run();
    return 0;
};