#ifndef CREDITSELECTBUTTON_H
#define CREDITSELECTBUTTON_H

class Texture;
class Vertex;

class CreditSelectButton
{
public:
	CreditSelectButton();
	~CreditSelectButton();

	void Draw();

private:
	void Fade();

private:
	Texture*			m_pTexture;
	Vertex*				m_pVertex;

	const float			m_kButtonWidth;
	const float			m_kButtonHeight;
	const float			m_kButtonPosX;
	const float			m_kButtonPosY;
};

#endif // !CREDITSELECTBUTTON_H