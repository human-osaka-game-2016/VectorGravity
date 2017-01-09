#include <Texture.h>
#include <Vertex.h>
#include "CreditMenuButton.h"

CreditMenuButton::CreditMenuButton() :
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_buttonAlpha(NULL),
m_fadeButtonTime(NULL),
m_kCreditButtonWidht(512.0f),
m_kCreditButtonHeight(96.0f),
m_kCreditButtonPosX(570.0f),
m_kCreditButtonPosY(516.0f)
{
	m_pTexture->LoadTexture("Resource/Texture/CreditMenuButton.png");
	m_pVertex->SetTextureSize(m_kCreditButtonWidht, m_kCreditButtonHeight);
}

CreditMenuButton::~CreditMenuButton()
{
	delete m_pTexture;
	delete m_pVertex;
}

void CreditMenuButton::Control()
{
	if (m_buttonAlpha < 255)
	{
		Fade();
	}
}

void CreditMenuButton::Draw()
{
	DWORD buttonColor = m_pVertex->AppointColor(m_buttonAlpha);
	m_pVertex->SetColor(buttonColor);

	m_pVertex->DrawLeftTop(m_kCreditButtonPosX, m_kCreditButtonPosY, m_pTexture);
}

void CreditMenuButton::Fade()
{
	m_fadeButtonTime++;

	if (m_fadeButtonTime > 90)
	{
		m_buttonAlpha += 3;
	}
}