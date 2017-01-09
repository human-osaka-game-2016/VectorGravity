#ifndef PAUSELOGO_H
#define PAUSELOGO_H

class Texture;
class Vertex;

class PauseLogo
{
public:
	PauseLogo();
	~PauseLogo();

	void Control();
	void Draw();

private:
	Texture*			m_pTexture;
	Vertex*				m_pVertex;

	const float			m_kLogoWidth;
	const float			m_kLogoHeight;
	const float			m_kLogoPosX;
	const float			m_kLogoPosY;

};

#endif // !CLEARLOGO_H