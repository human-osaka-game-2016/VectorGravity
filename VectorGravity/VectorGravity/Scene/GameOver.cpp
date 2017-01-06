/**
 * @file	GameOver.cpp
 * @breif	ゲームオーバーシーンのクラス実装
 * @author	shibata
 */

#include "GameOver.h"
#include "SceneFactory.h"

GameOver::GameOver() : 
m_returnLogoCount(0)
{

}

GameOver::~GameOver()
{

}

SceneID GameOver::Control()
{
	SceneID nextScene = SceneID::GAME_OVER_SCENE;

	while (m_returnLogoCount <= 60)
	{
		m_returnLogoCount++;
	}

	if (m_returnLogoCount >= 60)
	{
		nextScene = LOGO_SCENE;
	}
	m_returnLogoCount = 0;

	return nextScene;
}

void GameOver::Draw()
{

}