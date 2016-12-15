#include"BasePoint.h"
#include"../DataManager/DataManager.h"

BasePoint::BasePoint() :
m_pInputKey(&InputKey::Instance()),
m_basePointRect({ 100, 100, 1000, 400 }),
m_basePointDistance(0, 0)
{
}

BasePoint::~BasePoint()
{
}

void BasePoint::Control()
{
	m_pInputKey->CheckKey(DIK_UP, UP);
	m_pInputKey->CheckKey(DIK_DOWN, DOWN);
	m_pInputKey->CheckKey(DIK_LEFT, LEFT);
	m_pInputKey->CheckKey(DIK_RIGHT, RIGHT);

	m_playerPosX = DataManager::GetInstance().GetPositionXData();
	m_playerPosY = DataManager::GetInstance().GetPositionYData();

	if (m_playerPosX >= m_basePointRect.right)
	{
		if (m_pInputKey->m_key[RIGHT] == ON)
		{
			if (DataManager::GetInstance().GetPlayerFieldHits() == false)
			{
				m_basePointDistance.x += DataManager::GetInstance().GetMovingDistanceX();
			}
		}
	}
	if (m_playerPosX <= m_basePointRect.left)
	{
		if (m_pInputKey->m_key[LEFT] == ON)
		{
			if (DataManager::GetInstance().GetPlayerFieldHits() == false)
			{
				m_basePointDistance.x -= DataManager::GetInstance().GetMovingDistanceX();
			}
		}
	}
	if (m_playerPosY <= m_basePointRect.top)
	{
		if (m_pInputKey->m_key[UP] == ON)
		{
			if (DataManager::GetInstance().GetPlayerFieldHits() == false)
			{
				m_basePointDistance.y -= DataManager::GetInstance().GetMovingDistanceY();
			}
		}
	}
	if (m_playerPosY >= m_basePointRect.bottom)
	{
		if (m_pInputKey->m_key[DOWN] == ON)
		{
			if (DataManager::GetInstance().GetPlayerFieldHits() == false)
			{
				m_basePointDistance.y += DataManager::GetInstance().GetMovingDistanceY();
			}
		}
	}


	DataManager::GetInstance().SetBasePointRect(m_basePointRect);
	DataManager::GetInstance().SetBasePointDistance(m_basePointDistance);
}