#include "LogoScene.h"
#include "SceneFactory.h"

LogoScene::LogoScene()
{

}

LogoScene::~LogoScene()
{

}

SceneID LogoScene::Control()
{
	SceneID nextScene = SceneID::LOGO_SCENE;

	return nextScene;
}

void LogoScene::Draw()
{

}