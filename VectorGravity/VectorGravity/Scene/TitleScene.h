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

class TitleScene : public Scene
{
public:

	TitleScene();
	virtual ~TitleScene();

	virtual SceneID Control();
	virtual void Draw();

private:

	InputKey*			m_pInputKey;
	TitleBackground*	m_pTitleBackground;

};

#endif // !TITLESCENE_H