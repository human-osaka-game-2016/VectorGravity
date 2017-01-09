/**
 * @file	TitleBackground.h
 * @breif	タイトルシーン背景のクラスヘッダ
 * @author	shibata
 */

#ifndef TITLEBACKGROUND_H
#define TITLEBACKGROUND_H

#define BACKGROUND_WIDHT		1280
#define BACKGROUND_HEIGHT		720
#define BACKGROUND_POSITIONX	1280
#define BACKGROUND_POSITIONY	720

class Texture;
class Vertex;

class TitleBackground
{
public:

	TitleBackground();
	~TitleBackground();

	void Draw();

private:

	Texture*	m_pTexture;
	Vertex*		m_pVertex;

};

#endif // !TITLEBACKGROUND_H