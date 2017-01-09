/**
* @file		CreditRollScene.h
* @breif	クレジットロールシーンのクラスヘッダ
* @author	shibata
*/

#ifndef CREDITROLLSCENE_H
#define CREDITROLLSCENE_H

#include "Scene.h"

class InputKey;
class InputContlloer;
class CreditSelectButton;
class CreditTitleButton;
class CreditLogo;
class CreditRoll;

class CreditRollScene : public Scene
{
public:
	CreditRollScene();
	virtual ~CreditRollScene();

	virtual SceneID Control();
	virtual void Draw();

private:
	InputKey*				m_pInputKey;
	InputContlloer*			m_pInputContlloer;
	CreditTitleButton*		m_pCreditTitleButton;
	CreditSelectButton*		m_pCreditSelectButton;
	CreditLogo*				m_pCreditLogo;
	CreditRoll*				m_pCreditRoll;

};

#endif // !CREDITROLLSCENE_H