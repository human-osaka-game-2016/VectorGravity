#ifndef CREDITBUTTON_H
#define CREDITBUTTON_H

class Texture;
class Vertex;

class CreditButton
{
public:
	CreditButton();
	~CreditButton();

	void Control();
	void Draw();

private:
	void Fade();

private:
	Texture*		m_pTexture;
	Vertex*			m_pVertex;

	const float		m_kTitleButtonWidht;
	const float		m_kTitleButtonHeight;
	const float		m_kTitleButtonPosX;
	const float		m_kTitleButtonPosY;
	int				m_buttonAlpha;
	int				m_fadeButtonTime;

};

#endif // !CREDITBUTTON_H