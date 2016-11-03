/**
 * @file SceneFactory.h
 * @breif �V�[���t�@�N�g���[�w�b�_�[
 * @author shibata
 */

#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

enum SceneID
{
	LOGOSCENE,
	TITLESCENE,
	GAMESCENE,
	PAUSESCENE,
	RESULTSCENE,
	FINISHSCENE,
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
