/**
* @file		TitleScene.h
* @breif	タイトルシーンのクラスヘッダ
* @author	shibata
*/

#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "Scene.h"

class TitleScene : public Scene
{
public:

	TitleScene();
	virtual ~TitleScene();

	virtual SceneID Control();
	virtual void Draw();
};

#endif // !TITLESCENE_H