#include <Texture.h>
#include <Vertex.h>
#include "TitleButton.h"

TitleButton::TitleButton() :
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_kTitleButtonWidht(256.0f),
m_kTitleButtonHeight(64.0f),
m_kTitleButtonPosX(570.0f),
m_kTitleButtonPosY(420.0f)
{
	m_pTexture->LoadTexture("Resource/Texture/PauseTitle.png");
	m_pVertex->SetTextureSize(m_kTitleButtonWidht, m_kTitleButtonHeight);
}

TitleButton::~TitleButton()
{
	delete m_pTexture;
	delete m_pVertex;
}

void TitleButton::Draw()
{
	m_pVertex->DrawLeftTop(m_kTitleButtonPosX, m_kTitleButtonPosY, m_pTexture);
}