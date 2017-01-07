#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include<Windows.h>
#include<d3dx9.h>
#include<vector>
#include "../MyRect.h"

enum PlayerDirection;

class DataManager
{
public:
	~DataManager();

	static void Create()
	{
		if (m_pDataManager == NULL)
		{
			m_pDataManager = new DataManager();
		}
	}

	static DataManager* GetInstance()
	{
		return m_pDataManager;
	}

	static void Delete()
	{
		delete m_pDataManager;
		m_pDataManager = NULL;
	}

	void SetPlayerPositionData(float x_, float y_)
	{
		m_playerPosX = x_;
		m_playerPosY = y_;
	}

	float GetPlayerPositionXData()
	{
		return m_playerPosX;
	}

	float GetPlayerPositionYData()
	{
		return m_playerPosY;
	}

	void SetEnemyPositionData(float x_, float y_)
	{
		m_enemyPosX = x_;
		m_enemyPosY = y_;
	}

	float GetEnemyPositionXData()
	{
		return m_enemyPosX;
	}

	float GetEnemyPositionYData()
	{
		return m_enemyPosY;
	}

	void SetBasePointRect(MyRect rect_)
	{
		m_basePointRect = rect_;
	}

	MyRect GetBasePoint()
	{
		return m_basePointRect;
	}

	void SetBasePointDistance(D3DXVECTOR2 distance_)
	{
		m_basePointDistance = distance_;
	}

	D3DXVECTOR2 GetBasePointDistance()
	{
		return m_basePointDistance;
	}

	void SetPlayerFieldHits(bool fieldhits_)
	{
		m_playerFieldHits = fieldhits_;
	}

	bool GetPlayerFieldHits()
	{
		return m_playerFieldHits;
	}

	void AddEnemyInitPos(D3DXVECTOR2 enemyinitpos_)
	{
		m_enemyInitPos.push_back(enemyinitpos_);
	}

	std::vector<D3DXVECTOR2>* GetEnemyInitPos()
	{
		return &m_enemyInitPos;
	}

	void ClearEnemyInitPos()
	{
		m_enemyInitPos.clear();
	}

	void SetPlayerInitPos(D3DXVECTOR2 playerinitpos_)
	{
		m_playerInitPos = playerinitpos_;
	}

	D3DXVECTOR2 GetPlayerInitPos()
	{
		return m_playerInitPos;
	}

	void SetGoalPointPos(D3DXVECTOR2 goalpoint_)
	{
		m_goalPointPos = goalpoint_;
	}

	D3DXVECTOR2 GetGoalPointPos()
	{
		return m_goalPointPos;
	}

	void SetBasePointMove(D3DXVECTOR2 basepointpoint_)
	{
		m_basePointMove = basepointpoint_;
	}

	D3DXVECTOR2 GetBasePointMove()
	{
		return m_basePointMove;
	}

	void SetPlayerXMoveSpeed(float playerxmovespeed_)
	{
		m_playerXMoveSpeed = playerxmovespeed_;
	}

	float GetPlayerXMoveSpeed()
	{
		return m_playerXMoveSpeed;
	}

	void SetPlayerYMoveSpeed(float playerymovespeed_)
	{
		m_playerYMoveSpeed = playerymovespeed_;
	}

	float GetPlayerYMoveSpeed()
	{
		return m_playerYMoveSpeed;
	}

	void SetPlayerDirection(PlayerDirection direction_)
	{
		m_playerDirection = direction_;
	}

	PlayerDirection GetPlayerDirection()
	{
		return m_playerDirection;
	}

	void SetNormalBulletHit(bool hit_)
	{
		m_normalBulletHit = hit_;
	}

	bool GetNormalBulletHit()
	{
		return m_normalBulletHit;
	}

	void SetPlayerDead(bool death_)
	{
		m_playerIsDeath = death_;
	}

	bool GetPlayerDead()
	{
		return m_playerIsDeath;
	}

	void SetStageClear(bool clear_)
	{
		m_playerIsStageClear = clear_;
	}

	bool GetStageClear()
	{
		return m_playerIsStageClear;
	}

private:
	DataManager();

	float m_playerPosX;
	float m_playerPosY;

	float m_enemyPosX;
	float m_enemyPosY;

	bool m_playerFieldHits;

	MyRect m_basePointRect;
	D3DXVECTOR2 m_basePointDistance;

	std::vector<D3DXVECTOR2> m_enemyInitPos;
	D3DXVECTOR2 m_playerInitPos;
	D3DXVECTOR2 m_goalPointPos;
	D3DXVECTOR2 m_basePointMove;

	float m_playerXMoveSpeed;
	float m_playerYMoveSpeed;

	PlayerDirection m_playerDirection;

	bool m_normalBulletHit;

	bool m_playerIsDeath;
	bool m_playerIsStageClear;

	bool m_enemyIsDeath;

	static DataManager* m_pDataManager;
};

#endif // !DATAMANAGER_H