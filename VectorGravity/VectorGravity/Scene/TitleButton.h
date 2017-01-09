#ifndef TITLEBUTTON_H
#define TITLEBUTTON_H

class Texture;
class Vertex;

class TitleButton
{
public:
	TitleButton();
	~TitleButton();

	void Draw();

private:
	Texture*		m_pTexture;
	Vertex*			m_pVertex;

	const float		m_kTitleButtonWidht;
	const float		m_kTitleButtonHeight;
	const float		m_kTitleButtonPosX;
	const float		m_kTitleButtonPosY;
};

#endif // !TITLEBUTTON_H