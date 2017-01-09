/**
* @file		TitleScene.h
* @breif	タイトルシーンのクラスヘッダ
* @author	shibata
*/

#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "Scene.h"

class TitleBackground;
class TitleLogo;
class MenuButton;
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

	TitleBackground*	m_pTitleBackground;
	TitleLogo*			m_pTitleLogo;
	MenuButton*			m_pMenuButton;
	SoundManager*		m_pSoundManager;

};

#endif // !TITLESCENE_H