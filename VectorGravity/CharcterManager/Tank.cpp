#include "Tank.h"

Tank::Tank() : Character(), m_pInputKey(&InputKeyBorad::GetInstance())
{
	m_texture.LoadTexture("Resource/Texture/Tank1_ƒÀ.png");

	m_tank = { 600, 430, 600 + TANKWIDTH, 430 + TANKHEIGHT };

	m_hitCount = 0;
	m_hits = false;
}

Tank::~Tank()
{
}

void Tank::Attack()
{
}

void Tank::Move()
{
}

void Tank::Control()
{
	m_pInputKey->KeyCheck(DIK_Z, Z);
	m_pInputKey->KeyCheck(DIK_X, X);
	m_pInputKey->KeyCheck(DIK_B, B);

	static LONG XMove = 0;
	static LONG YMove = 0;

	m_hits = Collision::getInstance().Check();

	if (m_hits == true)
	{
		m_hitCount++;
	}
	
	if (m_hitCount >= 1)
	{
		if (m_pInputKey->m_Key[X] == PUSH)
		{
			XMove = BLOWSPEED;
		}
		if (m_pInputKey->m_Key[Z] == PUSH)
		{
			YMove = -BLOWSPEED;
		}
		if (m_pInputKey->m_Key[B] == PUSH)
		{
			m_tank = { 600, 430, 600 + TANKWIDTH, 430 + TANKHEIGHT };
			m_hitCount = 0;
			XMove = 0;
			YMove = 0;
		}
	}

	m_tank.right += XMove;
	m_tank.left += XMove;
	m_tank.top += YMove;
	m_tank.bottom += YMove;

}

void Tank::Draw()
{
	CUSTOMVERTEX Tank[4]
	{
		{ m_tank.left,  m_tank.top,    1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ m_tank.right, m_tank.top,    1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ m_tank.right, m_tank.bottom, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ m_tank.left,  m_tank.bottom, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	if (m_hits == false)
	{
		Tank[0].tu = Tank[3].tu = 0;
		Tank[1].tu = Tank[2].tu = 0.5;
	}
	if (m_hitCount >= 1)
	{
		Tank[0].tu = Tank[3].tu = 0.5;
		Tank[1].tu = Tank[2].tu = 1.0;
	}

	m_texture.SetTexture(Tank);
}