#include "GoalPoint.h"
#include <Vertex.h>
#include <Texture.h>
#include "../Collider/Collider.h"
#include "../Collider/CollisionManager.h"
#include "../DataManager/DataManager.h"

GoalPoint::GoalPoint(D3DXVECTOR2 initpos_) :
m_posX(initpos_.x),
m_posY(initpos_.y),
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_pCollider(new Collider(Collider::GOALPOINT_ID))
{
	m_pTexture->LoadTexture("Resource/Texture/Goal.png");
	m_pVertex->SetTextureSize(GOALPOINTWIDTH, GOALPOINTHEIGHT);
	m_GoalPointRect = { m_posX, m_posY, m_posX + GOALPOINTWIDTH, m_posY + GOALPOINTHEIGHT };
	CollisionManager::GetInstance()->SetCollider(m_pCollider);
}

GoalPoint::~GoalPoint()
{
	delete m_pCollider;
	delete m_pVertex;
	delete m_pTexture;
}

void GoalPoint::Control()
{
	m_base = DataManager::GetInstance()->GetBasePointDistance();

	m_baseRect.left   = m_GoalPointRect.left - m_base.x;
	m_baseRect.top    = m_GoalPointRect.top - m_base.y;
	m_baseRect.right  = m_GoalPointRect.right - m_base.x;
	m_baseRect.bottom = m_GoalPointRect.bottom - m_base.y;

	m_pCollider->SetRectData(m_baseRect);

	m_pCollider->ClearColliderIDs();
}

void GoalPoint::Draw()
{
	m_pVertex->DrawLeftTop(m_posX - m_base.x, m_posY - m_base.y, m_pTexture);
}