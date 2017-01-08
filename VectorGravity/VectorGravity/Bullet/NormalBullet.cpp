/**
 * @file	NormalBullet.cpp
 * @breif	í èÌíeÇÃÉNÉâÉXé¿ëï
 * @author	shibata
 */

#include "NormalBullet.h"
#include <Texture.h>
#include <Vertex.h>
#include <InputKey.h>
#include "../Collider/CollisionManager.h"
#include "../DataManager/DataManager.h"

NormalBullet::NormalBullet(Collider* pcollider_):
m_pInputKey(&InputKey::Instance()),
m_hits(false),
m_fieldHits(false),
m_pCollider(pcollider_)
{
	m_pVertex = new Vertex;

	m_playerPos.x = DataManager::GetInstance()->GetPlayerPositionXData();
	m_playerPos.y = DataManager::GetInstance()->GetPlayerPositionYData();

	//m_playerPos.x = DataManager::GetInstance()->GetPlayerInitPos().x;
	//m_playerPos.y = DataManager::GetInstance()->GetPlayerInitPos().y;

	m_posX = m_playerPos.x + 50;
	m_posY = m_playerPos.y + 45;
	m_normalBulletRect = { m_posX, m_posY, m_posX + NORMALBULLET_SIZE, m_posY + NORMALBULLET_SIZE };
	m_pVertex->SetTextureSize(NORMALBULLET_SIZE, NORMALBULLET_SIZE);
	m_hits = false;
	m_pCollider->SetIsActive(true);

	m_playerDirection = DataManager::GetInstance()->GetPlayerDirection();

}

NormalBullet::~NormalBullet()
{
	m_pCollider->SetIsActive(false);
	delete m_pVertex;
}

void NormalBullet::Control()
{
	m_base = DataManager::GetInstance()->GetBasePointDistance();

	m_baseRect.left   = m_normalBulletRect.left   - m_base.x;
	m_baseRect.top    = m_normalBulletRect.top    - m_base.y;
	m_baseRect.right  = m_normalBulletRect.right  - m_base.x;
	m_baseRect.bottom = m_normalBulletRect.bottom - m_base.y;

	m_pCollider->SetRectData(m_normalBulletRect);

	distance = DataManager::GetInstance()->GetBasePointDistance();

	m_colliderIDs = m_pCollider->GetColliderIDs();

	for (int i = 0; i < m_colliderIDs.size(); i++)
	{
		if (m_colliderIDs[i] == Collider::TANK_ID)
		{
		}
		if (m_colliderIDs[i] == Collider::SOLDIER_ID)
		{
			m_hits = true;
		}
	}

	m_fieldHits = CollisionManager::GetInstance()->HasHitField(m_normalBulletRect.right, m_normalBulletRect.bottom - 16, distance);

	if (m_hits == true || m_fieldHits == true)
	{
		DataManager::GetInstance()->SetNormalBulletHit(true);
	}
	else
	{
		DataManager::GetInstance()->SetNormalBulletHit(false);
	}

	Attack();
	m_pCollider->ClearColliderIDs();
}

void NormalBullet::Draw()
{
	m_pVertex->DrawLeftTop(m_posX/* -m_base.x*/, m_posY/* - m_base.y*/, m_pTexture);
}

void NormalBullet::Bound()
{

}

void NormalBullet::Charge()
{

}

void NormalBullet::Attack()
{
	switch (m_playerDirection)
	{
	case Direction_Right:
		m_normalBulletRect.right += NORMALBULLET_SPEED;
		m_normalBulletRect.left  += NORMALBULLET_SPEED;
		m_posX					 += NORMALBULLET_SPEED;
		break;
	case Direction_Left:
		m_normalBulletRect.right -= NORMALBULLET_SPEED;
		m_normalBulletRect.left  -= NORMALBULLET_SPEED;
		m_posX					 -= NORMALBULLET_SPEED;
		break;
	}

}