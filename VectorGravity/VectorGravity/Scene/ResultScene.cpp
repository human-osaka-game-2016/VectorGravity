/**
 * @file	ResultScene.cpp
 * @breif	���U���g�V�[���̃N���X����
 * @author	shibata
 */

#include "ResultScene.h"
#include "SceneFactory.h"

ResultScene::ResultScene()
{

}

ResultScene::~ResultScene()
{

}

SceneID ResultScene::Control()
{
	SceneID nextScene = SceneID::RESULT_SCENE;

	return nextScene;
}

void ResultScene::Draw()
{

}