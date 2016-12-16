/**
 * @file	LogoScene.cpp
 * @breif	ロゴシーンのクラス実装
 * @author	shibata
 */

#include "LogoScene.h"
#include "SceneFactory.h"
#include "TeamLogo.h"
#include <InputKey.h>

LogoScene::LogoScene() : 
m_pTeamLogo(new TeamLogo),
m_pInputKey(&InputKey::Instance())
{

}

LogoScene::~LogoScene()
{
	delete m_pTeamLogo;
}

SceneID LogoScene::Control()
{
	m_pInputKey->CheckKey(DIK_RETURN, ENTER);

	SceneID nextScene = SceneID::LOGO_SCENE;

	if (m_pTeamLogo->Control())
	{
		nextScene = SceneID::TITLE_SCENE;
	}

	if (m_pInputKey->m_key[ENTER] == ON)
	{
		nextScene = SceneID::TITLE_SCENE;
	}

	return nextScene;
}

void LogoScene::Draw()
{
	m_pTeamLogo->Draw();
}