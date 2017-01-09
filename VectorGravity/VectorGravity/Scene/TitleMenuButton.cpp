#include <Texture.h>
#include <Vertex.h>
#include "TitleMenuButton.h"

TitleMenuButton::TitleMenuButton() : 
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_buttonAlpha(NULL),
m_fadeButtonTime(NULL),
m_kTitleButtonWidht(256.0f),
m_kTitleButtonHeight(96.0f),
m_kTitleButtonPosX(570.0f),
m_kTitleButtonPosY(420.0f)
{
	m_pTexture->LoadTexture("Resource/Texture/TitleMenuButton.png");
	m_pVertex->SetTextureSize(m_kTitleButtonWidht, m_kTitleButtonHeight);
}

TitleMenuButton::~TitleMenuButton()
{
	delete m_pTexture;
	delete m_pVertex;
}

void TitleMenuButton::Control()
{
	if (m_buttonAlpha < 255)
	{
		Fade();
	}
}

void TitleMenuButton::Draw()
{
	DWORD buttonColor = m_pVertex->AppointColor(m_buttonAlpha);
	m_pVertex->SetColor(buttonColor);

	m_pVertex->DrawLeftTop(m_kTitleButtonPosX, m_kTitleButtonPosY, m_pTexture);
}

void TitleMenuButton::Fade()
{
	m_fadeButtonTime++;

	if (m_fadeButtonTime > 90)
	{
		m_buttonAlpha += 3;
	}
}