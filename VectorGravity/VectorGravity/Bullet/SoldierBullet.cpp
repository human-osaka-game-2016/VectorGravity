#include "SoldierBullet.h"
#include <Texture.h>
#include <Vertex.h>
#include <InputKey.h>
#include "../Collider/CollisionManager.h"
#include "../DataManager/DataManager.h"

SoldierBullet::SoldierBullet(Collider* pcollider_) :
m_pInputKey(&InputKey::Instance()),
m_hits(false),
m_fieldHits(false),
m_pCollider(pcollider_)
{
	m_pVertex2 = new Vertex;

	m_posX = DataManager::GetInstance().GetEnemyPositionXData();
	m_posY = DataManager::GetInstance().GetEnemyPositionYData();
	m_soldierBulletRect = { m_posX, m_posY, m_posX + SOLDIERBULLET_SIZE, m_posY + SOLDIERBULLET_SIZE };
	m_pVertex2->SetTextureSize(SOLDIERBULLET_SIZE, SOLDIERBULLET_SIZE);
	m_hits = false;
	m_pCollider->SetIsActive(true);

}

SoldierBullet::~SoldierBullet()
{
	delete m_pVertex2;
	m_pCollider->SetIsActive(false);
	
}

void SoldierBullet::Control()
{
	m_pCollider->SetRectData(m_soldierBulletRect);

	distance = DataManager::GetInstance().GetBasePointDistance();

	m_colliderIDs = m_pCollider->GetColliderIDs();

	for (int i = 0; i < m_colliderIDs.size(); i++)
	{
		if (m_colliderIDs[i] == Collider::PLAYER_ID)
		{
		}
		if (m_colliderIDs[i] == Collider::SOLDIER_ID)
		{
		}
	}


	Attack();
	m_pCollider->ClearColliderIDs();

}

void SoldierBullet::Draw()
{
	m_pVertex2->DrawLeftTop(m_posX, m_posY, m_pTexture2);
}

void SoldierBullet::Attack()
{
	m_soldierBulletRect.right -= SOLDIERBULLET_SPEED;
	m_soldierBulletRect.left  -= SOLDIERBULLET_SPEED;
	m_posX                    -= SOLDIERBULLET_SPEED;
}