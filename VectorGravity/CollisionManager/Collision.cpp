#include"Collision.h"


Collision::Collision()
{
	/*
	Player player;
	m_player = player.GetPlayerRect();

	���̏����́i���͎b��I��player�Ƃ��Ă��܂����j�A�Փ˂��镨�̂̏����ʒu���擾���邱�Ƃ��ł��܂��B
	*/

	m_object2 = m_tank.GetTankRect();
}

Collision::~Collision()
{
}

bool Collision::Check()
{
	if (
		(m_object1.left   < m_object2.right)				//Object�ɂ͏Փ˂���Q�̕��̂��`���邽�߁A���O�͕ύX�����\��������܂��B
		&& (m_object1.right  > m_object2.left)
		&& (m_object1.top    < m_object2.bottom)
		&& (m_object1.bottom > m_object2.top)
		)
	{
		return true;
	}
	return false;
}