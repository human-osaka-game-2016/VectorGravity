/**
 * @file	CreditRollScene.cpp
 * @breif	�N���W�b�g���[���V�[���̃N���X����
 * @author	shibata
 */

#include "CreditRollScene.h"
#include "SceneFactory.h"


CreditRollScene::CreditRollScene()
{

}

CreditRollScene::~CreditRollScene()
{

}

SceneID CreditRollScene::Control()
{
	SceneID nextScene = SceneID::CREDIT_ROLL_SCENE;

	return nextScene;
}

void CreditRollScene::Draw()
{

}