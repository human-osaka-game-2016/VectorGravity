/**
 * @file	LogoScene.cpp
 * @breif	ロゴシーンのクラス実装
 * @author	shibata
 */

#include "LogoScene.h"
#include "SceneFactory.h"
#include "TeamLogo.h"
#include <InputKey.h>
#include <InputContlloer.h>

LogoScene::LogoScene() : 
m_pTeamLogo(new TeamLogo),
m_pInputKey(&InputKey::Instance()),
m_pInputContlloer(&InputContlloer::Instance())
{

}

LogoScene::~LogoScene()
{
	delete m_pTeamLogo;
}

SceneID LogoScene::Control()
{
	m_pInputKey->CheckKey(DIK_RETURN, ENTER);
	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_A, A_BUTTON);

	SceneID nextScene = SceneID::LOGO_SCENE;

	if (m_pTeamLogo->Control())
	{
		nextScene = SceneID::TITLE_SCENE;
	}

	if (m_pInputKey->m_key[ENTER] == ON || m_pInputContlloer->m_padButton[CONTLLOER_1][A_BUTTON] == PAD_ON)
	{
		nextScene = SceneID::TITLE_SCENE;
	}

	return nextScene;
}

void LogoScene::Draw()
{
	m_pTeamLogo->Draw();
}