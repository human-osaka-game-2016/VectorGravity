#include "SceneFactory.h"
#include "LogoScene.h"
#include "TitleScene.h"
#include "GameScene.h"

Scene* SceneFactory::CreateScene(SceneID sceneID_)
{
	Scene* pScene = nullptr;

	switch (sceneID_)
	{
	case LOGOSCENE:
		pScene = new LogoScene;
		break;

	case TITLESCENE:
		pScene = new TitleScene;
		break;

	case GAMESCENE:
		pScene = new GameScene;
		break;

	case PAUSESCENE:

		break;

	case RESULTSCENE:

		break;

	case FINISHSCENE:
		break;
	default:
		break;
	}

	return pScene;
}

