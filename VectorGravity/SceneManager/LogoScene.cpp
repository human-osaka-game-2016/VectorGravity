#include "LogoScene.h"
#include "SceneFactory.h"

LogoScene::LogoScene() : Scene(SceneID::LOGO_SCENE)
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