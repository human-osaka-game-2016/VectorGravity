#include "TitleScene.h"
#include "SceneFactory.h"

TitleScene::TitleScene() : Scene(SceneID::TITLE_SCENE)
{

}

TitleScene::~TitleScene()
{

}

SceneID TitleScene::Control()
{
	SceneID nextScene = SceneID::TITLE_SCENE;

	return nextScene;

}

void TitleScene::Draw()
{

}