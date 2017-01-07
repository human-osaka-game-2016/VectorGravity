#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <vector>
#include <d3dx9.h>
#include "../Stage/Stage.h"

class Collider;
class TestStage;
class Stage;

class CollisionManager
{
public:
	~CollisionManager();

	static void Create()
	{
		if (m_pCollisionManager == NULL)
		{
			m_pCollisionManager = new CollisionManager();
		}
	}

	static CollisionManager* GetInstance()
	{
		return m_pCollisionManager;
	}

	static void Delete()
	{
		delete m_pCollisionManager;
		m_pCollisionManager = NULL;
	}

	void Control();

	int SetCollider(Collider* pCollider_)
	{
		int collider = m_pCollider.size();;
		m_pCollider.push_back(pCollider_);		//m_pCollider��pCollider��z��̈�ԍŌ�ɑ����B
		return collider;
	}

	void SetNotCollider(int index)
	{
		m_notCollider.push_back(index);
	}

	void ClearBuffer()
	{
		m_pCollider.clear();			//�X�e�[�W���J�ڂ����ۂɁAm_pCollider�ɓo�^�����R���W�����f�[�^��S�ĊJ������֐�		Buffer�̈Ӗ��𒲂ׂ� => �q�ɂ̂��Ƃ炵��
	}

	void SetStage(Stage* stage_);

	bool HasHitField(float posX_, float posY_, D3DXVECTOR2 distance_);

private:
	CollisionManager();

	std::vector<Collider*> m_pCollider;

	Stage* m_pStage;

	int** m_stageData;

	int m_stageHeight;
	int m_stageWidth;

	std::vector<int> m_notCollider;

	static CollisionManager* m_pCollisionManager;
};

#endif // !COLLISIONMANAGER_H