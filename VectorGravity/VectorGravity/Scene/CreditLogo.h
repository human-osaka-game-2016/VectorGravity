#ifndef CREDITLOGO_H
#define CREDITLOGO_H

class Texture;
class Vertex;

class CreditLogo
{
public:
	CreditLogo();
	~CreditLogo();

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

#endif // !CREDITLOGO_H