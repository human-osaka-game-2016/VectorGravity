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
class CreditLogo;
class CreditButton;
class CursorButton;
class StaffLogo;

class CreditRollScene : public Scene
{
public:
	CreditRollScene();
	virtual ~CreditRollScene();

	virtual SceneID Control();
	virtual void Draw();

private:
	CreditLogo*		m_pCreditLogo;
	CreditButton*	m_pCreditButton;
	CursorButton*	m_pCursorButton;
	StaffLogo*		m_pStaffLogo;
	InputKey*		m_pInputKey;
	InputContlloer*	m_pInputContlloer;

	int m_inputCount;
};

#endif // !CREDITROLLSCENE_H