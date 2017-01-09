/**
 * @file	TitleLogo.h
 * @breif	タイトルロゴのクラスヘッダ
 * @author	shibata
 */

#ifndef TITLELOGO_H
#define TITLELOGO_H

class Texture;
class Vertex;

class TitleLogo
{
public:
	TitleLogo();
	~TitleLogo();

	void Draw();

private:
	Texture*	m_pLogoTexture;
	Vertex*		m_pLogoVertex;
	const float m_LogoWidth;
	const float m_LogoHeight;
	float		m_LogoPosX;
	float		m_LogoPosY;
	int			m_slideCount;

};

#endif // !TITLELOGO_H