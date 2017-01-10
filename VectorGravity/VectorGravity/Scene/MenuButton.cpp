/**
 * @file	MenuButton.cpp
 * @breif	メニューボタンのクラス実装
 * @author	shibata
 */

#include "MenuButton.h"
#include <Texture.h>
#include <Vertex.h>
#include <InputContlloer.h>
#include <InputKey.h>

MenuButton::MenuButton() : 
m_pInputContlloer(&InputContlloer::Instance()),
m_pInputKey(&InputKey::Instance()),
m_pButtonTexture(new Texture),
m_pButtonVertex(new Vertex),
m_kButtonWidth(800.0f),
m_kButtonHeight(128.0f),
m_kButtonPosX(640.0f),
m_kButtonPosY(620.0f)
{	
	m_pButtonTexture->LoadTexture("Resource/Texture/MenuButton.png");
	m_pButtonVertex->SetTextureSize(m_kButtonWidth, m_kButtonHeight);
}

MenuButton::~MenuButton()
{
	delete m_pButtonVertex;
	delete m_pButtonTexture;
}

bool MenuButton::Control()
{
	m_pInputKey->CheckKey(DIK_RETURN, ENTER);
	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_A, A_BUTTON);
	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_START, START_BUTTON);
	

	if (m_pInputKey->m_key[ENTER] == ON || m_pInputContlloer->m_padButton[CONTLLOER_1][A_BUTTON] == PAD_ON || m_pInputContlloer->m_padButton[CONTLLOER_1][START_BUTTON] == PAD_ON)
	{
		return true;
	}

	return false;
}

void MenuButton::Draw()
{
	m_pButtonVertex->DrawCenter(m_kButtonPosX, m_kButtonPosY, m_pButtonTexture);
}