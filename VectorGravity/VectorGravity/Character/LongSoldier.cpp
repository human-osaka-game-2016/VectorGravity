#include "LongSoldier.h"
#include <Vertex.h>
#include <Texture.h>
#include "../Collider/Collider.h"
#include "../Collider/CollisionManager.h"
#include "../DataManager/DataManager.h"

LongSoldier::LongSoldier(D3DXVECTOR2 initpos_) :
m_pCollider(new Collider(Collider::SOLDIER_ID))
{
	m_pVertex2 = new Vertex;
	m_pVertex2->SetTextureSize(LONGSOLDIER_SIZE, LONGSOLDIER_SIZE, 0.25, 0.5, 0.125, 0.375);

	m_posX = initpos_.x;
	m_posY = initpos_.y;

	m_longSoldierRect = { m_posX, m_posY, m_posX + LONGSOLDIER_SIZE, m_posY + LONGSOLDIER_SIZE };

	m_isDeath = false;

	CollisionManager::getInstance().SetCollider(m_pCollider);
}

LongSoldier::~LongSoldier()
{
	delete m_pVertex2;
}

void LongSoldier::Control()
{
	m_base = DataManager::GetInstance().GetBasePointDistance();

	m_baseRect.left   = m_longSoldierRect.left - m_base.x;
	m_baseRect.top    = m_longSoldierRect.top - m_base.y;
	m_baseRect.right  = m_longSoldierRect.right - m_base.x;
	m_baseRect.bottom = m_longSoldierRect.bottom - m_base.y;

	m_pCollider->SetRectData(m_baseRect);

	m_colliderIDs = m_pCollider->GetColliderIDs();

	for (int i = 0; i < m_colliderIDs.size(); i++)
	{
		if (m_colliderIDs[i] == Collider::NORMALBULLET_ID)
		{

		}
		if (m_colliderIDs[i] == Collider::PLAYER_ID)
		{
		}
	}

	m_pCollider->ClearColliderIDs();

}

void LongSoldier::Draw()
{
	m_pVertex2->DrawLeftTop(m_posX - m_base.x, m_posY - m_base.y, m_pTexture);
}