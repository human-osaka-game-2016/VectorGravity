#include "SceneManager.h"
#include "SceneFactory.h"

SceneManager::SceneManager() :
m_pScene(NULL),
m_state(CREATE),
m_nextSceneID(SceneID::GAMESCENE),
m_pGraphicsDevice(&GraphicsDevice::GetInstance()),
m_pInputKey(&InputKeyBorad::GetInstance()), 
m_gameEnd(false)
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

	m_pGraphicsDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	m_pGraphicsDevice->DrawStart();

	Render();

	m_pGraphicsDevice->DrawEnd();

	return m_gameEnd;
}

void SceneManager::Control()
{
	if (m_pScene == NULL)
	{
		m_currentSceneID = m_nextSceneID;

		if (m_currentSceneID == FINISHSCENE)
		{
			m_gameEnd = true;
			return;
		}
	}
	else
	{
		m_currentSceneID = m_pScene->GetSceneID();
	}

	switch (m_state)
	{
	case CREATE:

		m_pScene = SceneFactory::Instance().CreateScene(m_currentSceneID);

		m_state = RUN;

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
	if (m_state == RUN)
	{
		return;
	}

	if (!m_pScene == NULL)
	{
		m_pScene->Draw();
	}
}