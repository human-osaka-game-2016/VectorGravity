/**
 * @file	StageManager.cpp
 * @breif	�X�e�[�W���Ǘ�����N���X����
 * @author	shibata
 */

#include "StageManager.h"
#include "Stage1.h"

StageManager::StageManager() :
m_pStage1(new Stage1)

{

}

StageManager::~StageManager()
{
	m_pStage1->StageRelease();
	delete m_pStage1;
}

void StageManager::Control()
{
	m_pStage1->Control();
}

void StageManager::Draw()
{
	m_pStage1->Draw();
}