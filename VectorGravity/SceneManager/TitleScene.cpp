#include "TitleScene.h"
#include "SceneFactory.h"

TitleScene::TitleScene() : Scene(SceneID::TITLESCENE)
{

}

TitleScene::~TitleScene()
{

}

SceneID TitleScene::Control()
{
	SceneID nextScene = SceneID::TITLESCENE;

	return nextScene;

}

void TitleScene::Draw()
{

}