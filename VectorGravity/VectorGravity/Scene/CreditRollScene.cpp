/**
 * @file	CreditRollScene.cpp
 * @breif	クレジットロールシーンのクラス実装
 * @author	shibata
 */

#include "CreditRollScene.h"
#include "SceneFactory.h"
#include "CreditLogo.h"
#include "CreditButton.h"
#include "CursorButton.h"
#include "StaffLogo.h"
#include <InputContlloer.h>
#include <InputKey.h>

CreditRollScene::CreditRollScene() :
m_pCreditLogo(new CreditLogo),
m_pCreditButton(new CreditButton),
m_pCursorButton(new CursorButton),
m_pStaffLogo(new StaffLogo),
m_pInputKey(&InputKey::Instance()),
m_pInputContlloer(&InputContlloer::Instance()),
m_inputCount(NULL)
{
}

CreditRollScene::~CreditRollScene()
{
	delete m_pCreditLogo;
	delete m_pCreditButton;
	delete m_pCursorButton;
	delete m_pStaffLogo;
}

SceneID CreditRollScene::Control()
{
	SceneID nextScene = SceneID::CREDIT_ROLL_SCENE;

	m_pInputKey->CheckKey(DIK_RETURN, ENTER);

	m_pCreditLogo->Control();
	m_pCreditButton->Control();
	m_pCursorButton->Control();
	m_pStaffLogo->Control();

	m_inputCount++;

	if (m_inputCount > 240)
	{
		if (m_pInputKey->m_key[ENTER] == ON)
		{
			nextScene = LOGO_SCENE;
		}
	}

	return nextScene;
}

void CreditRollScene::Draw()
{
	m_pCreditLogo->Draw();
	m_pCreditButton->Draw();
	m_pCursorButton->Draw();
	m_pStaffLogo->Draw();
}