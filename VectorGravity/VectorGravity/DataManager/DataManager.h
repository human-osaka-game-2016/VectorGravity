#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include<Windows.h>
#include<d3dx9.h>

class DataManager
{
public:
	~DataManager();

	static DataManager& GetInstance()
	{
		static DataManager DataManager;

		return DataManager;
	}

	void SetPositionData(LONG x_, LONG y_)
	{
		m_posX = x_;
		m_posY = y_;
	}

	float GetPositionXData()
	{
		return m_posX;
	}

	float GetPositionYData()
	{
		return m_posY;
	}

	void SetMovingDistanceX(float x_)
	{
		m_movingDistanceX = x_;
	}
	void SetMovingDistanceY(float y_)
	{
		m_movingDistanceY = y_;
	}

	float GetMovingDistanceX()
	{
		return m_movingDistanceX;
	}
	float GetMovingDistanceY()
	{
		return m_movingDistanceY;
	}

	void SetBasePointRect(RECT rect_)
	{
		m_basePointRect = rect_;
	}

	RECT GetBasePoint()
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

private:
	DataManager();

	float m_posX;
	float m_posY;

	float m_movingDistanceX;
	float m_movingDistanceY;

	bool m_playerFieldHits;

	RECT m_basePointRect;
	D3DXVECTOR2 m_basePointDistance;
};

#endif // !DATAMANAGER_H