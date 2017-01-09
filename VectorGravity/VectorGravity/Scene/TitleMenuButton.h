#ifndef TITLEMENUBUTTON_H
#define TITLEMENUBUTTON_H

class Texture;
class Vertex;

class TitleMenuButton
{
public:
	TitleMenuButton();
	~TitleMenuButton();

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

#endif // !TITLEMENUBUTTON_H