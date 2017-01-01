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
m_pCollider(pcollider_)
{
	m_playerPos.x = DataManager::GetInstance().GetPlayerPositionXData();
	m_playerPos.y = DataManager::GetInstance().GetPlayerPositionYData();

	m_pVertex = new Vertex;

	m_posX = m_playerPos.x;;
	m_posY = m_playerPos.y;;
	m_normalBulletRect = { m_posX, m_posY, m_posX + NORMALBULLET_SIZE, m_posY + NORMALBULLET_SIZE };
	m_pVertex->SetTextureSize(NORMALBULLET_SIZE, NORMALBULLET_SIZE);
	m_hits = false;
	m_pCollider->SetIsActive(true);

	m_playerDirection = DataManager::GetInstance().GetPlayerDirection();

}

NormalBullet::~NormalBullet()
{
	delete m_pVertex;
	m_pCollider->SetIsActive(false);
}

void NormalBullet::Control()
{
	m_pCollider->SetRectData(m_normalBulletRect);
	Attack();
	m_pCollider->ClearColliderIDs();
}

void NormalBullet::Draw()
{
	m_pVertex->DrawLeftTop(m_posX, m_posY, m_pTexture);
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