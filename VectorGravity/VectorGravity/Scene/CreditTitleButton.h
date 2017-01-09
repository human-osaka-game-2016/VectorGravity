#ifndef CREDITTITLEBUTTON_H
#define CREDITTITLEBUTTON_H

class Texture;
class Vertex;

class CreditTitleButton
{
public:
	CreditTitleButton();
	~CreditTitleButton();

	void Draw();

private:
	Texture*		m_pTexture;
	Vertex*			m_pVertex;

	const float		m_kTitleButtonWidht;
	const float		m_kTitleButtonHeight;
	const float		m_kTitleButtonPosX;
	const float		m_kTitleButtonPosY;
};

#endif // !CREDITTITLEBUTTON_H