#include "Robo2.h"

Robo2::Robo2() : Obj()
{
	m_texture.LoadTexture("Lasjina.png");

	m_robo2 = { 300, 300, 400, 400 };
	//m_robo2 = Collision::getInstance().GetRobo2Rect();
	
	width = 100;
	height = 100;

}

Robo2::~Robo2()
{
}

void Robo2::Control()
{
}

void Robo2::Draw()
{

	CUSTOMVERTEX enemy[4]
	{
		{ m_robo2.left,  m_robo2.top,    1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ m_robo2.right, m_robo2.top,    1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ m_robo2.right, m_robo2.bottom, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ m_robo2.left,  m_robo2.bottom, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	m_texture.SetTexture(enemy);
}