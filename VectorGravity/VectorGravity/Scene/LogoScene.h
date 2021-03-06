/**
* @file		LogoScene.h
* @breif	ロゴシーンのクラスヘッダ
* @author	shibata
*/

#ifndef LOGOSCENE_H
#define LOGOSCENE_H

#include "Scene.h"

class TeamLogo;
class InputKey;
class InputContlloer;

class LogoScene : public Scene
{
public:
	LogoScene();
	virtual ~LogoScene();

	virtual SceneID Control();
	virtual void Draw();

private:

	InputKey*			m_pInputKey;
	InputContlloer*		m_pInputContlloer;
	TeamLogo*			m_pTeamLogo;
};

#endif // !LOGOSCENE_H