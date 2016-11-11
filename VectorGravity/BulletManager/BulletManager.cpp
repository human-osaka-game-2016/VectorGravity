#include "BulletManager.h"
#include "Bullet.h"
#include "NormalBullet.h"
#include "../StateManager/StateManager.h"

BulletManager::BulletManager() : 
m_pNormalBullet(NULL),
m_pStateManager(&StateManager::GetInstance())
{
	
}

BulletManager::~BulletManager()
{
	delete m_pNormalBullet;
}

void BulletManager::Control()
{
	if (m_pNormalBullet == NULL)
	{
		return;
	}

	Bullet* bulletControlList[1] = 
	{
		m_pNormalBullet
	};

	for (int i = 0; i < 1; i++)
	{
		bulletControlList[i]->Control();
	}
}

void BulletManager::Draw()
{
	if (m_pNormalBullet == NULL)
	{
		return;
	}

	Bullet* bulletDrawList[1] = 
	{
		m_pNormalBullet
	};

	for (int i = 0; i < 1; i++)
	{
		bulletDrawList[i]->Draw();
	}
}

void BulletManager::Create()
{
	m_pNormalBullet = new NormalBullet;
	m_vectorDirection = m_pStateManager->GetVectorDirection();
}