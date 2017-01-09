#ifndef PAUSESELECTBUTTON_H
#define PAUSESELECTBUTTON_H

class Texture;
class Vertex;
class InputKey;
class InputContlloer;

class PauseSelectButton
{
public:
	PauseSelectButton();
	~PauseSelectButton();

	void Control();
	void Draw();

	bool GetUpOrDown()
	{
		return m_onTop;
	}

private:
	void Fade();

private:
	Texture*			m_pTexture;
	Vertex*				m_pVertex;
	InputKey*			m_pInputKey;
	InputContlloer*		m_pInputContlloer;

	const float			m_kButtonWidth;
	const float			m_kButtonHeight;
	const float			m_kTopButtonPosX;
	const float			m_kTopButtonPosY;
	const float			m_kDownButtonPosX;
	const float			m_kDownButtonPosY;
	bool				m_onTop;
	int					m_buttonAlpha;
	int					m_flashingTime;

};

#endif // !PAUSESELECTBUTTON_H