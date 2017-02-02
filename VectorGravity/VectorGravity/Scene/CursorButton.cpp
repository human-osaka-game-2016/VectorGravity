#include "CursorButton.h"
#include <Texture.h>
#include <Vertex.h>

CursorButton::CursorButton() :
m_fadeButtonTime(NULL),
m_buttonAlpha(NULL),
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_kButtonWidth(64.0f),
m_kButtonHeight(64.0f),
m_kButtonPosX(950.0f),
m_kButtonPosY(650.0f),
m_flashingTime(NULL),
m_isFadeFinish(false),
m_SelectButtonState(FADE_ID)
{
	m_pTexture->LoadTexture("Resource/Texture/Cursor.png");
	m_pVertex->SetTextureSize(m_kButtonWidth, m_kButtonHeight);
}

CursorButton::~CursorButton()
{
	delete m_pTexture;
	delete m_pVertex;
}

void CursorButton::Control()
{
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

void CursorButton::Draw()
{
	DWORD buttonColor = m_pVertex->AppointColor(m_buttonAlpha);
	m_pVertex->SetColor(buttonColor);

	m_pVertex->DrawCenter(m_kButtonPosX, m_kButtonPosY, m_pTexture);
}

void CursorButton::Fade()
{
	m_fadeButtonTime++;

	if (m_fadeButtonTime > 90)
	{
		m_buttonAlpha += 3;
	}
}