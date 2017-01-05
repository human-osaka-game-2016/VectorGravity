/**
 * @file	GameOver.cpp
 * @breif	ゲームオーバーシーンのクラス実装
 * @author	shibata
 */

#include "GameOver.h"
#include "SceneFactory.h"

GameOver::GameOver()
{

}

GameOver::~GameOver()
{

}

SceneID GameOver::Control()
{
	SceneID nextScene = SceneID::GAME_OVER_SCENE;

	return nextScene;
}

void GameOver::Draw()
{

}