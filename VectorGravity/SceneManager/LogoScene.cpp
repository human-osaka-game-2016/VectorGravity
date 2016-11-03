#include "LogoScene.h"
#include "SceneFactory.h"

LogoScene::LogoScene() : Scene(SceneID::LOGOSCENE)
{

}

LogoScene::~LogoScene()
{

}

SceneID LogoScene::Control()
{
	SceneID nextScene = SceneID::LOGOSCENE;

	return nextScene;
}

void LogoScene::Draw()
{

}