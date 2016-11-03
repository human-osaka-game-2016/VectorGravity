#include "Scene.h"

Scene::Scene(SceneID sceneID_) : m_sceneID(sceneID_)
{

}

Scene::~Scene()
{

}

SceneID Scene::Control()
{
	return m_sceneID;
}

void Scene::Draw()
{

}

SceneID Scene::GetSceneID()
{
	return m_sceneID;
}