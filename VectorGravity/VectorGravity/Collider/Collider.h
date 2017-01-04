#ifndef COLLIDER_H
#define COLLIDER_H

#include <windows.h>
#include <string>
#include <vector>
#include "../MyRect.h"

class Collider
{
public:

	enum ColliderID
	{
		PLAYER_ID,
		TANK_ID,
		CANNON_ID,
		SOLDIER_ID,
		NORMALBULLET_ID,
		ENEMYBULLET_ID,
		GOALPOINT_ID,
		IDMAX,
	};

	Collider(ColliderID idname_);
	~Collider();

	void SetRectData(MyRect object1_)			//CollisionManagerに矩形情報をSetするための関数	
	{
		m_rectData = object1_;
	}

	MyRect GetRectData()			//衝突判定をしたいオブジェクトのControl関数の最初に置いておく。
	{
		return m_rectData;
	}


	ColliderID GetColliderID()
	{
		return m_ID;
	}

	std::vector<ColliderID> GetColliderIDs()
	{
		return m_objectIDs;
	}

	void AddColliderIDs(ColliderID idname_)
	{
		m_objectIDs.push_back(idname_);
	}

	void SetIsActive(bool active_)
	{
		m_isActive = active_;
	}

	bool GetIsActive()
	{
		return m_isActive;
	}

	void ClearColliderIDs()
	{
		m_objectIDs.clear();			//毎フレーム登録したvectorを開放するためのもの
	}

private:
	ColliderID m_ID;			//衝突する物体の文字列

	std::vector<ColliderID> m_objectIDs;		//名前は仮起き　　衝突した相手の名前

	MyRect m_rectData;		//衝突判定するための矩形のサイズ

	bool m_isActive;
};

#endif // !COLLIDER_H