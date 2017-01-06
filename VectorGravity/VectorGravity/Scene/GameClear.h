/**
 * @file	GameClear.h
 * @breif	�Q�[���N���A�V�[���̃N���X�w�b�_
 * @author	shibata
 */

#ifndef GAMECLEAR_H
#define GAMECLEAR_H

#include "Scene.h"

class GameClear :public Scene
{
public:

	GameClear();
	virtual ~GameClear();

	SceneID Control();
	void Draw();

private:
	int m_returnLogoCount;
};

#endif // !GAMECLEAR_H