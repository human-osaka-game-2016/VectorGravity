#include <Texture.h>
#include <Vertex.h>
#include "ContinuButton.h"

ContinuButton::ContinuButton() :
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_kContinuButtonWidht(512.0f),
m_kContinuButtonHeight(64.0f),
m_kContinuButtonPosX(500.0f),
m_kContinuButtonPosY(494.0f)
{
	m_pTexture->LoadTexture("Resource/Texture/ContinueLogo.png");
	m_pVertex->SetTextureSize(m_kContinuButtonWidht, m_kContinuButtonHeight);
}

ContinuButton::~ContinuButton()
{
	delete m_pTexture;
	delete m_pVertex;
}

void ContinuButton::Draw()
{
	m_pVertex->DrawLeftTop(m_kContinuButtonPosX, m_kContinuButtonPosY, m_pTexture);
}