#include "Pause.h"
#include "PauseLogo.h"
#include "Pausebackground.h"
#include "PauseSelectButton.h"
#include "TitleButton.h"
#include "ContinuButton.h"
#include "SceneFactory.h"
#include "../StateManager/StateManager.h"
#include <InputContlloer.h>
#include <InputKey.h>
#include <Texture.h>
#include <Vertex.h>

Pause::Pause() :
m_pInputKey(&InputKey::Instance()),
m_pInputContlloer(&InputContlloer::Instance()),
m_isPause(false),
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_pPauseLogo(new PauseLogo),
m_pPauseBackground(new PauseBackground),
m_pPauseSelectButton(new PauseSelectButton),
m_pTitleButton(new TitleButton),
m_pContinuButton(new ContinuButton),
m_pStateManager(&StateManager::Instance()),
m_count(NULL)
{

}

Pause::~Pause()
{
	delete m_pTexture;
	delete m_pVertex;
	delete m_pPauseLogo;
	delete m_pPauseBackground;
	delete m_pPauseSelectButton;
	delete m_pTitleButton;
	delete m_pContinuButton;
}

SceneID Pause::Control()
{
	m_pInputKey->CheckKey(DIK_RETURN, ENTER);

	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_A, A_BUTTON);
	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_BACK, BACK_BUTTON);

	m_pPauseSelectButton->Control();

	if (m_pInputKey->m_key[ENTER] == PUSH || m_pInputContlloer->m_padButton[CONTLLOER_1][A_BUTTON] == PAD_PUSH)
	{
		if (m_pPauseSelectButton->GetUpOrDown())
		{
			return TITLE_SCENE;
		}
		else
		{
			m_isPause = false;
			m_pStateManager->SetPauses(m_isPause);
		}
	}

	

	return GAME_SCENE;

}

void Pause::Draw()
{
	m_pPauseBackground->Draw();
	m_pPauseLogo->Draw();
	m_pPauseSelectButton->Draw();
	m_pTitleButton->Draw();
	m_pContinuButton->Draw();
}
