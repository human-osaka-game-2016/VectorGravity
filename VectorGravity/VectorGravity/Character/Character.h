/**
* @file		Character.h
* @breif	キャラクターの親クラスヘッダ
* @author	shibata
*/

#ifndef CHARCTER_H
#define CHARCTER_H

class Texture;
class Vertex;

class Character
{
public:

	Character();
	virtual ~Character();

	virtual void Control() = 0;
	virtual void Draw() = 0;

protected:

	Texture*	m_pTexture;
	Texture*	m_pTexture2;
	Vertex*		m_pVertex;
	float		m_posX;
	float		m_posY;
	bool		m_isDeath;

};

#endif // !CHARCTER_H