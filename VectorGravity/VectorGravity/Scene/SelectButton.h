#ifndef SELECTBUTTON_H
#define SELECTBUTTON_H

class Texture;
class Vertex;
class InputKey;
class InputContlloer;

enum SelectButtonState
{
	FADE_ID,
	FLASHING
};

class SelectButton
{
public:
	SelectButton();
	~SelectButton();

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
	SelectButtonState	m_SelectButtonState;

	const float			m_kButtonWidth;
	const float			m_kButtonHeight;
	const float			m_kTopButtonPosX;
	const float			m_kTopButtonPosY;
	const float			m_kDownButtonPosX;
	const float			m_kDownButtonPosY;
	int					m_buttonAlpha;
	int					m_fadeButtonTime;
	bool				m_onTop;
	bool				m_isFadeFinish;
	int					m_flashingTime;

};

#endif // !SELECTBUTTON_H