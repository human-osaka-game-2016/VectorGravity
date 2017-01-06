/**
* @file		GameScene.h
* @breif	ゲームシーンのクラスヘッダ
* @author	shibata
*/

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"

class ObjectManager;
class SoundManager;
class DataManager;
class InputKey;


enum GameSceneSound
{
	GAME_BGM,
};

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

	ObjectManager*		m_pObjectManager;
	SoundManager*		m_pSoundManager;
	DataManager*		m_pDataManager;
	InputKey*			m_pInputKey;
	bool				m_pauses;
};

#endif // !GAMESCENE_H