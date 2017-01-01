#include "Tank.h"
#include <Vertex.h>
#include <InputKey.h>

Tank::Tank() :
m_pInputKey(&InputKey::Instance())
{
	m_posX = 100;
	m_posY = 100;
	m_pVertex = new Vertex;
	m_pVertex->SetTextureSize(TANKWIDTH, TANKHEIGHT, 0.25, 0.1875);
}

Tank::~Tank()
{
	delete m_pVertex;
}

void Tank::Control()
{
}

void Tank::Draw()
{
	m_pVertex->DrawCenter(m_posX, m_posY, m_pTexture);
}