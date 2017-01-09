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
class Texture;
class Vertex;
class Pause;
class StateManager;
class InputContlloer;

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
	InputContlloer*		m_pInputContlloer;
	Texture*			m_pTexture;
	Vertex*				m_pVertex;
	Pause*				m_pPause;
	StateManager*		m_pStateManager;

	bool				m_pauses;
};

#endif // !GAMESCENE_H