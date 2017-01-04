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

	void SetRectData(MyRect object1_)			//CollisionManager�ɋ�`����Set���邽�߂̊֐�	
	{
		m_rectData = object1_;
	}

	MyRect GetRectData()			//�Փ˔�����������I�u�W�F�N�g��Control�֐��̍ŏ��ɒu���Ă����B
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
		m_objectIDs.clear();			//���t���[���o�^����vector���J�����邽�߂̂���
	}

private:
	ColliderID m_ID;			//�Փ˂��镨�̂̕�����

	std::vector<ColliderID> m_objectIDs;		//���O�͉��N���@�@�Փ˂�������̖��O

	MyRect m_rectData;		//�Փ˔��肷�邽�߂̋�`�̃T�C�Y

	bool m_isActive;
};

#endif // !COLLIDER_H