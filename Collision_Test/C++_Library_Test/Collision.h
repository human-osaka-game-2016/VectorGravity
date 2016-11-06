#ifndef COLLISION_H
#define COLLISION_H

#include<windows.h>
//#include<vector>
//#include"obj.h"
#include"robo.h"
#include"robo2.h"

enum COLLISIONID
{
	PLAYERID,
	ENEMYID,
	BULLETID,
	FIELDID,
	COLLISIONMAX
};

enum HITCHECK
{
	TOPHIT,
	BOTTOMHIT,
	RIGHTHIT,
	LEFTHIT,
	NOHIT,
	HITMAX
};

class Collision
{
public:
	bool Check();
	HITCHECK CheckField();

	static Collision& getInstance()
	{
		static Collision Collision;

		return Collision;
	}
	~Collision();

	/*RECT GetRoboRect()
	{
		return m_player;
	}

	RECT GetRobo2Rect()
	{
		return m_enemy;
	}*/

	void SetRoboRec(RECT robo);

private:
	Collision();

	RECT m_player;
	RECT m_enemy;
	
	//std::vector<RECT> m_EnemyRectData;
	//std::vector<RECT> m_PlayerRectData;
	//std::vector<RECT> m_BulletRectData;

};

#endif COLLISION_H