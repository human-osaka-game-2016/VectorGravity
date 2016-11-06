#include"Collision.h"

Collision::Collision()
{
	/*m_player = { 100, 100, 100, 100 };
	
	Robo robo;
	robo.SetRect(m_player);
	
	m_enemy = { 300, 500, 300, 500 };
	
	Robo2 robo2;
	robo2.SetRect(m_enemy);*/

	Robo robo;
	m_player = robo.GetPlayerRect();

	Robo2 robo2;
	m_enemy = robo2.GetEnemyRect();

}

Collision::~Collision()
{
}

void Collision::SetRoboRec(RECT robo)
{
	m_player = robo;
}


bool Collision::Check()
{

	if (
		   (m_player.left   < m_enemy.right)
		&& (m_player.right  > m_enemy.left)
		&& (m_player.top    < m_enemy.bottom)
		&& (m_player.bottom > m_enemy.top)
		)
	{
		return true;
	}
	return false;
}