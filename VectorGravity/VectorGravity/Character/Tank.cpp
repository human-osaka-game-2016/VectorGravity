#include "Tank.h"
#include <InputKey.h>
#include <Vertex.h>
#include <Texture.h>

Tank::Tank() :
m_pVertex(new Vertex),
m_pInputKey(&InputKey::Instance())
{
	m_posX = 100;
	m_posY = 100;
	m_pTexture = new Texture;
	m_pTexture->LoadTexture("Resource/Texture/Total_File2.png");
	m_pVertex->SetTextureSize(TANKWIDTH, TANKHEIGHT, 0.25, 0.1875);
}

Tank::~Tank()
{
	delete m_pVertex;
	delete m_pTexture;
}

void Tank::Control()
{
	m_pInputKey->CheckKey(DIK_UP, UP);
	m_pInputKey->CheckKey(DIK_DOWN, DOWN);
	m_pInputKey->CheckKey(DIK_LEFT, LEFT);
	m_pInputKey->CheckKey(DIK_RIGHT, RIGHT);

	if (m_pInputKey->m_key[UP] == ON)
	{
		m_posY -= MOVE_SPEED;
	}
	if (m_pInputKey->m_key[DOWN] == ON)
	{
		m_posY += MOVE_SPEED;
	}
	if (m_pInputKey->m_key[LEFT] == ON)
	{
		m_posX -= MOVE_SPEED;
	}
	if (m_pInputKey->m_key[RIGHT] == ON)
	{
		m_posX += MOVE_SPEED;
	}
}

void Tank::Draw()
{
	m_pVertex->DrawCenter(m_posX, m_posY, m_pTexture);
}