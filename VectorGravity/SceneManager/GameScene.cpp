#include "GameScene.h"
#include "SceneFactory.h"

GameScene::GameScene() : Scene(SceneID::GAMESCENE)
{

}

GameScene::~GameScene()
{

}

SceneID GameScene::Control()
{
	SceneID nextScene = SceneID::GAMESCENE;

	return nextScene;
}

void GameScene::Draw()
{

}