#include "Tank.h"

Tank::Tank()
{
	m_texture.LoadTexture("Tank_É¿.png");

	m_tank = { 600, 300, 600 + TankWidth, 300 + TankHeight };
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
}

void Tank::Draw()
{
	CUSTOMVERTEX Tank[4]
	{
		{ m_tank.left, m_tank.top, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ m_tank.right, m_tank.top, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ m_tank.right, m_tank.bottom, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ m_tank.left, m_tank.bottom, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	m_texture.SetTexture(Tank);
}