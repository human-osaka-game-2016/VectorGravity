#include "CreditSelectButton.h"
#include <Texture.h>
#include <Vertex.h>


CreditSelectButton::CreditSelectButton() :
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_kButtonWidth(64.0f),
m_kButtonHeight(64.0f),
m_kButtonPosX(970.0f),
m_kButtonPosY(670.0f)
{
	m_pTexture->LoadTexture("Resource/Texture/Cursor.png");
	m_pVertex->SetTextureSize(m_kButtonWidth, m_kButtonHeight);
}

CreditSelectButton::~CreditSelectButton()
{
	delete m_pTexture;
	delete m_pVertex;
}

void CreditSelectButton::Draw()
{
	m_pVertex->DrawCenter(m_kButtonPosX, m_kButtonPosY, m_pTexture);
}