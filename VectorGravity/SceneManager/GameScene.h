/**
 * @file GameScene.h
 * @breif ゲームシーンのクラスヘッダー
 * @author shibata
 */

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"

class ObjectManager;

class GameScene : public Scene
{
public:

	GameScene();
	virtual ~GameScene();

	virtual SceneID Control();
	virtual void Draw();
	void PauseControl();
	void PauseDraw();

private:

	ObjectManager* m_pObjectManager;
	bool m_pauses;
};

#endif // !GAMESCENE_H
