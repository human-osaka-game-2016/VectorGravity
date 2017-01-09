#ifndef CREDITLOGO_H
#define CREDITLOGO_H

class Texture;
class Vertex;

class CreditLogo
{
public:
	CreditLogo();
	~CreditLogo();

	void Draw();

private:
	Texture*			m_pTexture;
	Vertex*				m_pVertex;

	const float			m_kLogoWidth;
	const float			m_kLogoHeight;
	const float			m_kLogoPosX;
	const float			m_kLogoPosY;

};

#endif // !CREDITLOGO_H