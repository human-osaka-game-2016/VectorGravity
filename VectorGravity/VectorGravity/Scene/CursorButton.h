#ifndef CURSORBUTTON_H
#define CURSORBUTTON_H

class Texture;
class Vertex;
class InputKey;
class InputContlloer;

enum SelectButtonState
{
	FADE_ID,
	FLASHING
};

class CursorButton
{
public:
	CursorButton();
	~CursorButton();

	void Control();
	void Draw();

private:
	void Fade();

private:
	Texture*			m_pTexture;
	Vertex*				m_pVertex;
	SelectButtonState	m_SelectButtonState;

	const float			m_kButtonWidth;
	const float			m_kButtonHeight;
	const float			m_kButtonPosX;
	const float			m_kButtonPosY;
	int					m_buttonAlpha;
	int					m_fadeButtonTime;
	bool				m_isFadeFinish;
	int					m_flashingTime;

};

#endif // !CURSORBUTTON_H