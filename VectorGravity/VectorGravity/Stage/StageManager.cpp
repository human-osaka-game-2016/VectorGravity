/**
 * @file	StageManager.cpp
 * @breif	ステージを管理するクラス実装
 * @author	shibata
 */

#include "StageManager.h"
#include "../DataManager/DataManager.h"
#include "Stage1.h"
#include "GoalPoint.h"

StageManager::StageManager() :
m_pStage1(new Stage1)
{
	D3DXVECTOR2 m_basePointPos = DataManager::GetInstance()->GetGoalPointPos();

	m_pGoalPoint = new GoalPoint(m_basePointPos);

}

StageManager::~StageManager()
{
	delete m_pGoalPoint;
	m_pStage1->StageRelease();
	delete m_pStage1;
}

void StageManager::Control()
{
	m_pStage1->Control();
	m_pGoalPoint->Control();
}

void StageManager::Draw()
{
	m_pStage1->Draw();
	m_pGoalPoint->Draw();
}