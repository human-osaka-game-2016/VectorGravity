/**
* @file		CreditRollScene.h
* @breif	リザルトシーンのクラスヘッダ
* @author	shibata
*/

#ifndef RESULTSCENE_H
#define RESULTSCENE_H

#include "Scene.h"

class InputKey;
class InputContlloer;
class SoundManager;
class ClearLogo;
class GameOverLogo;
class SelectButton;
class TitleMenuButton;
class CreditMenuButton;
class DataManager;

enum ResultSound
{
	CLEAR_SOUND,
	GAMEOVER_SOUND,
};


class ResultScene : public Scene
{
public:
	ResultScene();
	virtual ~ResultScene();

	virtual SceneID Control();
	virtual void Draw();

private:
	InputKey*			m_pInputKey;
	InputContlloer*		m_pInputContlloer;
	SoundManager*		m_pSoundManager;
	ClearLogo*			m_pClearLogo;
	GameOverLogo*		m_pGameOverLogo;
	SelectButton*		m_pSelectButton;
	TitleMenuButton*	m_pTitleMenuButton;
	CreditMenuButton*	m_pCreditMenuButton;
	DataManager*		m_pDataManager;

	int					m_startControlTime;


};

#endif // !RESULTSCENE_H