/**
 * @file Scene.h
 * @breif シーンの基底クラスのヘッダー
 * @author shibata
 */

#ifndef SCENE_H
#define SCENE_H

#include "SceneFactory.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();
	virtual SceneID Control() = 0;
	virtual void Draw() = 0;
};

#endif // !SCENE_H
