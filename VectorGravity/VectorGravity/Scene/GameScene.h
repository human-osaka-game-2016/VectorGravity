/**
* @file		GameScene.h
* @breif	ゲームシーンのクラスヘッダ
* @author	shibata
*/

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"

class ObjectManager;
class Sound;

class GameScene : public Scene
{
public:

	GameScene();
	virtual ~GameScene();

	virtual SceneID Control();
	virtual void Draw();
	void ControlPause();
	void DrawPause();

private:

	ObjectManager*	m_pObjectManager;
	Sound*			m_pSound;
	bool			m_pauses;
};

#endif // !GAMESCENE_H