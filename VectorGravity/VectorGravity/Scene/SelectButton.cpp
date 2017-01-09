#include "SelectButton.h"
#include <Texture.h>
#include <Vertex.h>
#include <InputContlloer.h>
#include <InputKey.h>

SelectButton::SelectButton() :
m_pInputKey(&InputKey::Instance()),
m_pInputContlloer(&InputContlloer::Instance()),
m_fadeButtonTime(NULL),
m_buttonAlpha(NULL),
m_onTop(true),
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_kButtonWidth(64.0f),
m_kButtonHeight(64.0f),
m_kTopButtonPosX(506.0f),
m_kTopButtonPosY(475.0f),
m_kDownButtonPosX(506.0f),
m_kDownButtonPosY(560.0f),
m_flashingTime(NULL),
m_isFadeFinish(false),
m_SelectButtonState(FADE_ID)
{
	m_pTexture->LoadTexture("Resource/Texture/Cursor.png");
	m_pVertex->SetTextureSize(m_kButtonWidth, m_kButtonHeight);
}

SelectButton::~SelectButton()
{
	delete m_pTexture;
	delete m_pVertex;
}

void SelectButton::Control()
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


	switch (m_SelectButtonState)
	{
	case FADE_ID:
		if (m_buttonAlpha < 255)
		{
			Fade();

			if (m_buttonAlpha == 255)
			{
				m_SelectButtonState = FLASHING;
			}
		}
		break;

	case FLASHING:
		m_flashingTime++;

		if (m_flashingTime < 30)
		{
			m_buttonAlpha = 255;
		}
		else
		{
			m_buttonAlpha = 0;
		}

		if (m_flashingTime == 60)
		{
			m_flashingTime = 0;
		}

		break;
	}
}

void SelectButton::Draw()
{
	DWORD buttonColor = m_pVertex->AppointColor(m_buttonAlpha);
	m_pVertex->SetColor(buttonColor);

	if (m_onTop)
	{
		m_pVertex->DrawCenter(m_kTopButtonPosX, m_kTopButtonPosY, m_pTexture);
	}
	else
	{
		m_pVertex->DrawCenter(m_kDownButtonPosX, m_kDownButtonPosY, m_pTexture);
	}
}

void SelectButton::Fade()
{
	m_fadeButtonTime++;

	if (m_fadeButtonTime > 90)
	{
		m_buttonAlpha += 3;
	}
}