/**
 * @file SceneManager.h
 * @breif �V�[���̊Ǘ��N���X�̃w�b�_�[
 * @author shibata
 */

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <../c++ Library/DirectDrawTexture/DirectDrawTexture.h>
#include <../c++ Library/Input/DirectInput.h>
#include "Scene.h"

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)


enum SceneID;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Control();
	void Render();
	bool Run();

private:

	enum State
	{
		CREATE,
		RUN,
		RELEASE,
	};

	Scene*				m_pScene;
	InputKeyBorad*		m_pInputKey;
	GraphicsDevice*		m_pGraphicsDevice;
	State				m_state;
	SceneID				m_currentSceneID;
	SceneID				m_nextSceneID;
	bool				m_gameEnd;
	
};

#endif // !SCENEMANAGER_H