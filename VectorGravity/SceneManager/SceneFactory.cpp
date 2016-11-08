/**
 * @file SceneFactory.cpp
 * @breif シーンファクトリーのクラス実装
 * @author shibata
 */

#include "SceneFactory.h"
#include "LogoScene.h"
#include "TitleScene.h"
#include "GameScene.h"

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

	case RESULT_SCENE:

		break;

	case FINISH_SCENE:
		break;
	default:
		break;
	}

	return pScene;
}

