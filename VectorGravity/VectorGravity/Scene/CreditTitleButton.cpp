#include <Texture.h>
#include <Vertex.h>
#include "CreditTitleButton.h"

CreditTitleButton::CreditTitleButton() :
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_kTitleButtonWidht(256.0f),
m_kTitleButtonHeight(96.0f),
m_kTitleButtonPosX(1024.0f),
m_kTitleButtonPosY(624.0f)
{
	m_pTexture->LoadTexture("Resource/Texture/TitleMenuButton.png");
	m_pVertex->SetTextureSize(m_kTitleButtonWidht, m_kTitleButtonHeight);
}

CreditTitleButton::~CreditTitleButton()
{
	delete m_pTexture;
	delete m_pVertex;
}

void CreditTitleButton::Draw()
{
	m_pVertex->DrawLeftTop(m_kTitleButtonPosX, m_kTitleButtonPosY, m_pTexture);
}