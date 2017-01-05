/**
 * @file	EnemyBulletManager.cpp
 * @breif	“G‚Ì’e‚ğŠÇ—‚·‚éƒNƒ‰ƒXÀ‘•
 * @author	shibata
 */

#include "EnemyBulletManager.h"
#include "SoldierBullet.h"
#include "../Collider/Collider.h"
#include "../Collider/CollisionManager.h"
#include "../DataManager/DataManager.h"

const int EnemyBulletManager::m_BulletMax = 4;

EnemyBulletManager::EnemyBulletManager()
{
	for (int i = 0; i < m_BulletMax; i++)
	{
		m_pCollider[i] = new Collider(Collider::ENEMYBULLET_ID);
		m_pCollider[i]->SetIsActive(false);
		CollisionManager::getInstance().SetCollider(m_pCollider[i]);
	}
}

EnemyBulletManager::~EnemyBulletManager()
{
	delete m_pCollider[0];
	delete m_pCollider[1];
	delete m_pCollider[2];
	delete m_pCollider[3];
}

void EnemyBulletManager::Control()
{
	for (int i = 0; i < m_pSoldierBullets.size(); i++)
	{
		m_pSoldierBullets[i]->Control();

		if (m_pSoldierBullets[i]->GetRect().left > 1280)
		{
			delete m_pSoldierBullets[i];
			m_pSoldierBullets.erase(m_pSoldierBullets.begin() + i);
			m_BulletNum--;
		}
		else if (m_pSoldierBullets[i]->GetRect().right < 0)
		{
			delete m_pSoldierBullets[i];
			m_pSoldierBullets.erase(m_pSoldierBullets.begin() + i);
			m_BulletNum--;
		}

	}

}

void EnemyBulletManager::Draw()
{
	for (int i = 0; i < m_pSoldierBullets.size(); i++)
	{
		m_pSoldierBullets[i]->Draw();
	}
}

void EnemyBulletManager::CreateBullet(EnemyID enmeyID_)
{
	if (m_BulletNum < m_BulletMax)
	{
		m_pSoldierBullets.push_back(new SoldierBullet(m_pCollider[m_BulletNum]));
		m_BulletNum++;
	}
}