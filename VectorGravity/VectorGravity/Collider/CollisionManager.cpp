#include "CollisionManager.h"
#include "Collider.h"
#include "../Stage/Stage1.h"

CollisionManager* CollisionManager::m_pCollisionManager = NULL;

CollisionManager::CollisionManager()
{

}

CollisionManager::~CollisionManager()
{

}

void CollisionManager::Control()
{
	for (unsigned int i = 0; i < m_pCollider.size(); i++)
	{
		for (unsigned int k = 0; k < m_notCollider.size(); k++)
		{
			if (m_notCollider[k] == i)
			{
				continue;
			}
		}
		if (m_pCollider[i]->GetIsActive() == true)
		{
			for (unsigned int j = 0; j < m_pCollider.size(); j++)
			{
				for (unsigned int l = 0; l < m_notCollider.size(); l++)
				{
					if (m_notCollider[l] == j)
					{
						continue;
					}
				}
				if (m_pCollider[j]->GetIsActive() == true)
				{
					if (i != j)
					{
						if (
							(m_pCollider[i]->GetRectData().left   < m_pCollider[j]->GetRectData().right)
							&& (m_pCollider[i]->GetRectData().right  > m_pCollider[j]->GetRectData().left)
							&& (m_pCollider[i]->GetRectData().top    < m_pCollider[j]->GetRectData().bottom)
							&& (m_pCollider[i]->GetRectData().bottom > m_pCollider[j]->GetRectData().top)
							)
						{
							m_pCollider[i]->AddColliderIDs(m_pCollider[j]->GetColliderID());		//i‚Éj‚Æ“–‚½‚Á‚½‚Æ‹³‚¦‚é
							m_pCollider[j]->AddColliderIDs(m_pCollider[i]->GetColliderID());
						}
					}
				}
			}
		}
	}
}

void CollisionManager::SetStage(Stage* stage_)
{
	m_pStage = stage_;
	m_stageHeight = m_pStage->GetStageHeight();
	m_stageWidth = m_pStage->GetStageWidth();

	m_stageData = stage_->GetStageData();
}

bool CollisionManager::HasHitField(float posX_, float posY_, D3DXVECTOR2 distance_)
{
	int PosX = ((int)posX_ + distance_.x) / CHIP_SIZE;
	int PosY = ((int)posY_ + distance_.y) / CHIP_SIZE;

	if (m_stageHeight > PosY && m_stageWidth > PosX && PosY >= 0 && PosX >= 0)
	{
		if (m_stageData[PosY][PosX] == 1)
		{
			return true;
		}
	}
	return false;
}