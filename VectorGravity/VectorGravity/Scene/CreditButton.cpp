#include <Texture.h>
#include <Vertex.h>
#include "CreditButton.h"

CreditButton::CreditButton() :
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_buttonAlpha(NULL),
m_fadeButtonTime(NULL),
m_kTitleButtonWidht(256.0f),
m_kTitleButtonHeight(96.0f),
m_kTitleButtonPosX(1000.0f),
m_kTitleButtonPosY(600.0f)
{
	m_pTexture->LoadTexture("Resource/Texture/TitleMenuButton.png");
	m_pVertex->SetTextureSize(m_kTitleButtonWidht, m_kTitleButtonHeight);
}

CreditButton::~CreditButton()
{
	delete m_pTexture;
	delete m_pVertex;
}

void CreditButton::Control()
{
	if (m_buttonAlpha < 255)
	{
		Fade();
	}
}

void CreditButton::Draw()
{
	DWORD buttonColor = m_pVertex->AppointColor(m_buttonAlpha);
	m_pVertex->SetColor(buttonColor);

	m_pVertex->DrawLeftTop(m_kTitleButtonPosX, m_kTitleButtonPosY, m_pTexture);
}

void CreditButton::Fade()
{
	m_fadeButtonTime++;

	if (m_fadeButtonTime > 90)
	{
		m_buttonAlpha += 3;
	}
}