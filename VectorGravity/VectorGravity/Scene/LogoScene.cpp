/**
 * @file	LogoScene.cpp
 * @breif	ロゴシーンのクラス実装
 * @author	shibata
 */

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