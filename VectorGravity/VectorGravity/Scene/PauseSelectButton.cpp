#include "PauseSelectButton.h"
#include <Texture.h>
#include <Vertex.h>
#include <InputContlloer.h>
#include <InputKey.h>

PauseSelectButton::PauseSelectButton() :
m_pInputKey(&InputKey::Instance()),
m_pInputContlloer(&InputContlloer::Instance()),
m_onTop(true),
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_kButtonWidth(64.0f),
m_kButtonHeight(64.0f),
m_kTopButtonPosX(506.0f),
m_kTopButtonPosY(455.0f),
m_kDownButtonPosX(506.0f),
m_kDownButtonPosY(530.0f),
m_flashingTime(NULL),
m_buttonAlpha(255)
{
	m_pTexture->LoadTexture("Resource/Texture/Cursor.png");
	m_pVertex->SetTextureSize(m_kButtonWidth, m_kButtonHeight);
}

PauseSelectButton::~PauseSelectButton()
{
	delete m_pTexture;
	delete m_pVertex;
}

void PauseSelectButton::Control()
{
	m_pInputKey->CheckKey(DIK_UP, UP);
	m_pInputKey->CheckKey(DIK_DOWN, DOWN);

	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_DPAD_UP, DPAD_UP);
	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, DPAD_DOWN);

	if (m_pInputKey->m_key[UP] == PUSH || m_pInputContlloer->m_padButton[CONTLLOER_1][DPAD_UP] == PAD_PUSH)
	{
		m_onTop = true;
	}

	if (m_pInputKey->m_key[DOWN] == PUSH || m_pInputContlloer->m_padButton[CONTLLOER_1][DPAD_DOWN] == PAD_PUSH)
	{
		m_onTop = false;
	}
}

void PauseSelectButton::Draw()
{
	if (m_onTop)
	{
		m_pVertex->DrawCenter(m_kTopButtonPosX, m_kTopButtonPosY, m_pTexture);
	}
	else
	{
		m_pVertex->DrawCenter(m_kDownButtonPosX, m_kDownButtonPosY, m_pTexture);
	}
}