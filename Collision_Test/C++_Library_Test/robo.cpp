#include "Robo.h"

Robo::Robo() : Obj(), m_inputkeydevice(&InputKeyBorad::GetInstance())//, m_collision(&Collision::getInstance())
{
	m_texture.LoadTexture("Lupus.jpg");

	m_robo = {100, 100, 200, 200};
	//m_robo = Collision::getInstance().GetRoboRect();

	//// サイズ計算
	//width = 100;
	//height = 100;

	
}

Robo::~Robo()
{
}

void Robo::Control()
{
	
	//m_hit = m_collision->Check();
	//m_robo = Collision::getInstance().GetRoboRect();

	m_hit = Collision::getInstance().Check();

	if (m_hit == false)
	{
		if (m_inputkeydevice->m_Key[LEFT] == ON)
		{
			//m_robo = Collision::getInstance().GetRoboRect();

			m_robo.right -= MOVESPEED;
			m_robo.left -= MOVESPEED;
			//Collision::getInstance().Check();
		}
		if (m_inputkeydevice->m_Key[RIGHT] == ON)
		{
			//m_robo = Collision::getInstance().GetRoboRect();

			m_robo.right += MOVESPEED;
			m_robo.left += MOVESPEED;
			//Collision::getInstance().Check();
		}
		if (m_inputkeydevice->m_Key[UP] == ON)
		{
			//m_robo = Collision::getInstance().GetRoboRect();

			m_robo.top -= MOVESPEED;
			m_robo.bottom -= MOVESPEED;
			//Collision::getInstance().Check();
		}
		if (m_inputkeydevice->m_Key[DOWN] == ON)
		{
			//m_robo = Collision::getInstance().GetRoboRect();

			m_robo.top += MOVESPEED;
			m_robo.bottom += MOVESPEED;
			//Collision::getInstance().Check();
		}
	}
	else
	{
		m_robo.left = NOSPEED;
		m_robo.top = NOSPEED;
		m_robo.right = NOSPEED;
		m_robo.bottom = NOSPEED;
	}
	
	Collision::getInstance().SetRoboRec(m_robo);
}

void Robo::Draw()
{
	CUSTOMVERTEX player[4]
	{
		{ m_robo.left,  m_robo.top,    1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ m_robo.right, m_robo.top,    1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ m_robo.right, m_robo.bottom, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ m_robo.left,  m_robo.bottom, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	m_texture.SetTexture(player);
}