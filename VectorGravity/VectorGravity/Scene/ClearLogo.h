#ifndef CLEARLOGO_H
#define CLEARLOGO_H

class Texture;
class Vertex;

class ClearLogo
{
public:
	ClearLogo();
	~ClearLogo();

	void Control();
	void Draw();

private:
	void Fade();

private:
	Texture*			m_pTexture;
	Vertex*				m_pVertex;

	int					m_fadeStartTimer;
	int					m_LogoAlpha;
	const float			m_kLogoWidth;
	const float			m_kLogoHeight;
	const float			m_kLogoPosX;
	const float			m_kLogoPosY;

};

#endif // !CLEARLOGO_H