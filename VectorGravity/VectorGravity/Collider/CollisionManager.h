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

	void Control();

	static CollisionManager& getInstance()
	{
		static CollisionManager collisionManager;

		return collisionManager;
	}

	void SetCollider(Collider* pCollider_)
	{
		m_pCollider.push_back(pCollider_);		//m_pColliderにpColliderを配列の一番最後に足す。
	}

	void ClearBuffer()
	{
		m_pCollider.clear();			//ステージが遷移した際に、m_pColliderに登録したコリジョンデータを全て開放する関数		Bufferの意味を調べる => 倉庫のことらしい
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
};

#endif // !COLLISIONMANAGER_H