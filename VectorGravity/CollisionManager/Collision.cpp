#include"Collision.h"


Collision::Collision()
{
	/*
	Player player;
	m_player = player.GetPlayerRect();

	この処理は（今は暫定的にplayerとしていますが）、衝突する物体の初期位置を取得することができます。
	*/

	m_object2 = m_tank.GetTankRect();
}

Collision::~Collision()
{
}

bool Collision::Check()
{
	if (
		(m_object1.left   < m_object2.right)				//Objectには衝突する２つの物体を定義するため、名前は変更される可能性があります。
		&& (m_object1.right  > m_object2.left)
		&& (m_object1.top    < m_object2.bottom)
		&& (m_object1.bottom > m_object2.top)
		)
	{
		return true;
	}
	return false;
}