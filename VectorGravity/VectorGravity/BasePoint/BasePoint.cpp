#include "BasePoint.h"
#include "../DataManager/DataManager.h"
#include <InputKey.h>
#include <InputContlloer.h>


BasePoint::BasePoint() :
m_pInputKey(&InputKey::Instance()),
m_pInputContlloer(&InputContlloer::Instance()),
m_basePointRect({ 100, 100, 800, 450 }),
m_basePointDistance(0, 0)
{
	m_playerInitPos = DataManager::GetInstance().GetPlayerInitPos();

	m_playerDistance = m_playerInitPos;

	m_basePointDistance.x += m_playerDistance.x - m_playerInitPos.x;
	m_basePointDistance.y += m_playerDistance.y + m_playerInitPos.y;

	DataManager::GetInstance().SetBasePointRect(m_basePointRect);
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

	m_pInputContlloer->CheckStick(LEFT_THUMBSTICK, STICK_LEFT);
	m_pInputContlloer->CheckStick(LEFT_THUMBSTICK, STICK_RIGHT);

	m_playerPosX = DataManager::GetInstance().GetPlayerPositionXData();
	m_playerPosY = DataManager::GetInstance().GetPlayerPositionYData();

	if (m_playerPosX >= m_basePointRect.right)
	{
		if (m_pInputKey->m_key[RIGHT] == ON || m_pInputContlloer->m_padStick[CONTLLOER_1][STICK_RIGHT][LEFT_THUMBSTICK] == PAD_ON)
		{
				m_basePointDistance.x += DataManager::GetInstance().GetPlayerXMoveSpeed();
		}
	}
	else if (m_playerPosX <= m_basePointRect.left)
	{
		if (m_pInputKey->m_key[LEFT] == ON || m_pInputContlloer->m_padStick[CONTLLOER_1][STICK_LEFT][LEFT_THUMBSTICK] == PAD_ON)
		{
				m_basePointDistance.x -= DataManager::GetInstance().GetPlayerXMoveSpeed();
		}
	}

	if (m_playerPosY <= m_basePointRect.top)
	{
		if (DataManager::GetInstance().GetPlayerFieldHits() == false)
		{
			m_basePointDistance.y -= DataManager::GetInstance().GetPlayerYMoveSpeed();
		}
	}
	else if (m_playerPosY >= m_basePointRect.bottom)
	{
		if (DataManager::GetInstance().GetPlayerFieldHits() == false)
		{
			m_basePointDistance.y += DataManager::GetInstance().GetPlayerYMoveSpeed();
		}
	}

	DataManager::GetInstance().SetBasePointRect(m_basePointRect);
	DataManager::GetInstance().SetBasePointDistance(m_basePointDistance);
}