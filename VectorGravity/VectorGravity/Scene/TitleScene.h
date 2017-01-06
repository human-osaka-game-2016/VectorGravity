/**
* @file		TitleScene.h
* @breif	タイトルシーンのクラスヘッダ
* @author	shibata
*/

#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "Scene.h"

class TitleBackground;
class InputKey;
class InputContlloer;
class SoundManager;

enum TitleSound
{
	TITLE_SOUND
};

class TitleScene : public Scene
{
public:

	TitleScene();
	virtual ~TitleScene();

	virtual SceneID Control();
	virtual void Draw();

private:

	InputKey*			m_pInputKey;
	InputContlloer*		m_pInputContlloer;
	TitleBackground*	m_pTitleBackground;
	SoundManager*		m_pSoundManager;

};

#endif // !TITLESCENE_H