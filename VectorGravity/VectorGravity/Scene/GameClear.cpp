/**
 * @file	GameClear.cpp
 * @breif	ゲームクリアシーンのクラス実装
 * @author	shibata
 */

#include "GameClear.h"
#include "SceneFactory.h"

GameClear::GameClear()
{

}

GameClear::~GameClear()
{

}

SceneID GameClear::Control()
{
	SceneID nextScene = SceneID::GAME_CLEAR_SCENE;

	return nextScene;
}

void GameClear::Draw()
{

}