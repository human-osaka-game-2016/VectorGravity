#ifndef PAUSE_H
#define PAUSE_H

#include "Scene.h"

class InputKey;
class InputContlloer;
class Texture;
class Vertex;
class PauseLogo;
class PauseBackground;
class PauseSelectButton;
class TitleButton;
class ContinuButton;
enum SceneID;
class StateManager;

class Pause : public Scene
{
public:
	Pause();
	virtual ~Pause();

	virtual SceneID Control();
	void Draw();

	bool GetIsPause()
	{
		return m_isPause;
	}

private:
	InputKey*			m_pInputKey;
	InputContlloer*		m_pInputContlloer;	
	Texture*			m_pTexture;
	Vertex*				m_pVertex;
	PauseLogo*			m_pPauseLogo;
	PauseBackground*	m_pPauseBackground;
	PauseSelectButton*	m_pPauseSelectButton;
	TitleButton*		m_pTitleButton;
	ContinuButton*		m_pContinuButton;
	StateManager*		m_pStateManager;

	bool				m_isPause;
	int					m_count;

};

#endif // !PAUSE_H
