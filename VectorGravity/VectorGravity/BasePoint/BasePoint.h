#ifndef BASEPOINT_H
#define BASEPOINT_H

#include <windows.h>
#include <d3dx9.h>
#include "../MyRect.h"

class InputKey;
class InputContlloer;
class DataManager;

class BasePoint
{
public:
	BasePoint();
	~BasePoint();

	void Control();

private:

	InputKey*	    m_pInputKey;
	InputContlloer*	m_pInputContlloer;
	DataManager*	m_pDataManager;
	MyRect m_basePointRect;
	float m_posX;
	float m_posY;
	float m_playerPosX;
	float m_playerPosY;
	D3DXVECTOR2 m_basePointDistance;

	D3DXVECTOR2 m_playerInitPos;
	D3DXVECTOR2 m_playerDistance;

};

#endif // !BASEPOINT_H