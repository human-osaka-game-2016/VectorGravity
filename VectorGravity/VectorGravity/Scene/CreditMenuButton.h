#ifndef CREDITMENUBUTTON_H
#define CREDITMENUBUTTON_H

class Texture;
class Vertex;


class CreditMenuButton
{
public:
	CreditMenuButton();
	~CreditMenuButton();

	void Control();
	void Draw();

private:
	void Fade();

private:
	Texture*			m_pTexture;
	Vertex*				m_pVertex;

	const float		m_kCreditButtonWidht;
	const float		m_kCreditButtonHeight;
	const float		m_kCreditButtonPosX;
	const float		m_kCreditButtonPosY;
	int				m_buttonAlpha;
	int				m_fadeButtonTime;


};

#endif // !CREDITMENUBUTTON_H