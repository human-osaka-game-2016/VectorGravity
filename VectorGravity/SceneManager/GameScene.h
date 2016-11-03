/**
 * @file GameScene.h
 * @breif �Q�[���V�[���̃N���X�w�b�_�[
 * @author shibata
 */

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"

class GameScene : public Scene
{
public:

	GameScene();
	virtual ~GameScene();

	virtual SceneID Control();
	virtual void Draw();
};

#endif // !GAMESCENE_H
