#include "TitleScene.h"
#include "SceneFactory.h"

TitleScene::TitleScene()
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