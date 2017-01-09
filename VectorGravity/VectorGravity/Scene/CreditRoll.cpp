#include "CreditRoll.h"
#include <Texture.h>
#include <Vertex.h>

CreditRoll::CreditRoll() : 
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_kRollWidth(1024.0f),
m_kRollHeight(500.0f),
m_kRollPosX(135.0f),
m_kRollPosY(120.0f)
{
	m_pTexture->LoadTexture("Resource/Texture/BackGround.png");
	m_pVertex->SetTextureSize(m_kRollWidth, m_kRollHeight);
}

CreditRoll::~CreditRoll()
{
	delete m_pTexture;
	delete m_pVertex;
}

void CreditRoll::Draw()
{
	m_pVertex->DrawLeftTop(m_kRollPosX, m_kRollPosY, m_pTexture);
}
