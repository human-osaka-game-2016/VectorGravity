/**
* @file		SceneFactory.h
* @breif	�V�[���̐���������N���X�w�b�_
* @author	shibata
*/

#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

enum SceneID
{
	LOGO_SCENE,
	TITLE_SCENE,
	GAME_SCENE,
	RESULT_SCENE,
	CREDIT_ROLL_SCENE,
	FINISH,
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

	~SceneFactory(){}

private:

	SceneFactory(){}
};

#endif // !SCENEFACTORY_H