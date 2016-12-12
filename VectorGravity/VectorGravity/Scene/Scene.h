/**
* @file		Scene.h
* @breif	シーンの親クラスヘッダ
* @author	shibata
*/

#ifndef SCENE_H
#define SCENE_H

enum SceneID;

class Scene
{
public:
	Scene();
	virtual ~Scene();
	virtual SceneID Control() = 0;
	virtual void Draw() = 0;
};

#endif // !SCENE_H