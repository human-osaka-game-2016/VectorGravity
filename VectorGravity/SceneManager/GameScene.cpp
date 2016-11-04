#include "GameScene.h"
#include "SceneFactory.h"

GameScene::GameScene() : Scene(SceneID::GAME_SCENE)
{

}

GameScene::~GameScene()
{

}

SceneID GameScene::Control()
{
	SceneID nextScene = SceneID::GAME_SCENE;

	return nextScene;
}

void GameScene::Draw()
{

}