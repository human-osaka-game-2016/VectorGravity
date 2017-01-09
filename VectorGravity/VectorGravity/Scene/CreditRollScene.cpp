/**
 * @file	CreditRollScene.cpp
 * @breif	クレジットロールシーンのクラス実装
 * @author	shibata
 */

#include "CreditLogo.h"
#include "CreditRoll.h"
#include "CreditSelectButton.h"
#include "CreditTitleButton.h"
#include "CreditRollScene.h"
#include "SceneFactory.h"
#include <InputContlloer.h>
#include <InputKey.h>

CreditRollScene::CreditRollScene() : 
m_pInputKey(&InputKey::Instance()),
m_pInputContlloer(&InputContlloer::Instance()),
m_pCreditSelectButton(new CreditSelectButton),
m_pCreditTitleButton(new CreditTitleButton),
m_pCreditLogo(new CreditLogo),
m_pCreditRoll(new CreditRoll)
{

}

CreditRollScene::~CreditRollScene()
{
	delete m_pCreditSelectButton;
	delete m_pCreditTitleButton;
	delete m_pCreditLogo;
	delete m_pCreditRoll;
}

SceneID CreditRollScene::Control()
{
	SceneID nextScene = SceneID::CREDIT_ROLL_SCENE;

	m_pInputKey->CheckKey(DIK_RETURN, ENTER);

	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_A, A_BUTTON);

	if (m_pInputKey->m_key[ENTER] == PUSH || m_pInputContlloer->m_padButton[CONTLLOER_1][A_BUTTON] == PUSH)
	{
		nextScene = TITLE_SCENE;
	}


	return nextScene;
}

void CreditRollScene::Draw()
{
	m_pCreditSelectButton->Draw();
	m_pCreditTitleButton->Draw();
	m_pCreditLogo->Draw();
	m_pCreditRoll->Draw();
}