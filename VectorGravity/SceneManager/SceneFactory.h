/**
 * @file SceneFactory.h
 * @breif シーンファクトリーのクラスのヘッダー
 * @author shibata
 */

#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

enum SceneID
{
	LOGO_SCENE,
	TITLE_SCENE,
	GAME_SCENE,
	RESULT_SCENE,
	END_ROLL_SCENE,
	FINISH_SCENE,
};

class Scene;

class SceneFactory
{
public:

	static SceneFactory& Instance()
	{
		static SceneFactory sceneFactory;

		return sceneFactory;
	}

	Scene* CreateScene(SceneID sceneID_);

	virtual ~SceneFactory(){}

private:

	SceneFactory(){}
};




#endif // !SCENEFACTORY_H
