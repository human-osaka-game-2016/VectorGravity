/**
* @file SceneManager.cpp
* @breif シーンマネージャーのクラス実装
* @author shibata
*/

#include "SceneManager.h"
#include "SceneFactory.h"
#include "Scene.h"
#include <GraphicsDevice.h>
#include <InputDevice.h>
#include <InputKey.h>

SceneManager::SceneManager() :
m_pScene(nullptr),
m_state(CREATE),
m_currentSceneID(SceneID::GAME_SCENE),
m_nextSceneID(SceneID::GAME_SCENE),
m_pGraphicsDevice(&GraphicsDevice::Instance()),
m_pInputDevice(&InputDevice::Instance()),
m_pInputKey(new InputKey),
m_isGameEnd(false)
{
}

SceneManager::~SceneManager()
{
	if (m_pScene != nullptr)
	{
		delete m_pScene;
		m_pScene = nullptr;
	}
}

bool SceneManager::Run()
{
	m_pInputKey->GetKeyBoradState();

	Control();

	m_pGraphicsDevice->SetFVF();
	m_pGraphicsDevice->DrawStart();

	Render();

	m_pGraphicsDevice->DrawEnd();

	return m_isGameEnd;
}

void SceneManager::Control()
{
	if (m_pScene == nullptr)
	{
		m_currentSceneID = m_nextSceneID;

		if (m_currentSceneID == FINISH)
		{
			m_isGameEnd = true;
			return;
		}
	}

	switch (m_state)
	{
	case CREATE:

		m_pScene = SceneFactory::Instance().CreateScene(m_currentSceneID);

		m_state = RUN;
		break;

	case RUN:

		if ((m_nextSceneID = m_pScene->Control()) != m_currentSceneID)
		{
			m_state = RELEASE;
		}

		break;

	case RELEASE:

		if (m_pScene != nullptr)
		{
			delete m_pScene;
			m_pScene = nullptr;
		}

		m_state = CREATE;

		break;
	}
}

void SceneManager::Render()
{
	if (m_state != RUN)
	{
		return;
	}

	if (m_pScene != nullptr)
	{
		m_pScene->Draw();
	}
}