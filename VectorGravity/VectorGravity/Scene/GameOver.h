/**
 * @file	GameOver.cpp
 * @breif	ゲームオーバーシーンのクラス
 * @author	shibata
 */

#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Scene.h"

class GameOver : public Scene
{
public:

	GameOver();
	virtual ~GameOver();

	SceneID Control();
	void Draw();
};

#endif // !GAMEOVER_H