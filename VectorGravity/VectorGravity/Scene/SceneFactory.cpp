/**
* @file		SceneFactory.cpp
* @breif	シーンの生成をするクラス実装
* @author	shibata
*/

#include "SceneFactory.h"
#include "LogoScene.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "GameClear.h"
#include "GameOver.h"
#include "CreditRollScene.h"

Scene* SceneFactory::CreateScene(SceneID sceneID_)
{
	Scene* pScene = nullptr;

	switch (sceneID_)
	{
	case LOGO_SCENE:
		pScene = new LogoScene;
		break;

	case TITLE_SCENE:
		pScene = new TitleScene;
		break;

	case GAME_SCENE:
		pScene = new GameScene;
		break;

	case GAME_CLEAR_SCENE:
		pScene = new GameClear;
		break;

	case GAME_OVER_SCENE:
		pScene = new GameOver;
		break;

	case CREDIT_ROLL_SCENE:
		pScene = new CreditRollScene;
	case FINISH:
		break;
	default:
		break;
	}

	return pScene;
}