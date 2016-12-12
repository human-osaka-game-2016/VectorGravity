/**
* @file		CreditRollScene.h
* @breif	クレジットロールシーンのクラスヘッダ
* @author	shibata
*/

#ifndef CREDITROLLSCENE_H
#define CREDITROLLSCENE_H

#include "Scene.h"

class CreditRollScene : public Scene
{
public:
	CreditRollScene();
	virtual ~CreditRollScene();

	virtual SceneID Control();
	virtual void Draw();

};

#endif // !CREDITROLLSCENE_H