/**
 * @file	PlayerBulletManager.cpp
 * @breif	プレイヤーの弾を管理するクラス実装
 * @author	shibata
 */

#include "PlayerBulletManager.h"
#include "NormalBullet.h"
#include "../Collider/Collider.h"
#include "../Collider/CollisionManager.h"
#include "../DataManager/DataManager.h"

const int PlayerBulletManager::m_BulletMax = 4;

PlayerBulletManager::PlayerBulletManager()
{
	for (int i = 0; i < m_BulletMax; i++)
	{
		m_pCollider[i] = new Collider(Collider::NORMALBULLET_ID);
		m_pCollider[i]->SetIsActive(false);
		CollisionManager::getInstance().SetCollider(m_pCollider[i]);
	}
}

PlayerBulletManager::~PlayerBulletManager()
{
	delete m_pCollider[0];
	delete m_pCollider[1];
	delete m_pCollider[2];
	delete m_pCollider[3];
}

void PlayerBulletManager::Control()
{
	for (int i = 0; i < m_pNormalBullets.size(); i++)
	{
		m_pNormalBullets[i]->Control();

		if (m_pNormalBullets[i]->GetRect().left > 1280)
		{
			delete m_pNormalBullets[i];
			m_pNormalBullets.erase(m_pNormalBullets.begin() + i);
			m_BulletNum--;
		}
		else if (m_pNormalBullets[i]->GetRect().right < 0)
		{
			delete m_pNormalBullets[i];
			m_pNormalBullets.erase(m_pNormalBullets.begin() + i);
			m_BulletNum--;
		}

		if (DataManager::GetInstance().GetNormalBulletHit())
		{
			delete m_pNormalBullets[i];
			m_pNormalBullets.erase(m_pNormalBullets.begin() + i);
			m_BulletNum--;
		}
	}
}

void PlayerBulletManager::Draw()
{
	for (int i = 0; i < m_pNormalBullets.size(); i++)
	{
		m_pNormalBullets[i]->Draw();
	}
}

void PlayerBulletManager::CreateBullet()
{
	if (m_BulletNum < m_BulletMax)
	{
		m_pNormalBullets.push_back(new NormalBullet(m_pCollider[m_BulletNum]));
		m_BulletNum++;
	}
}