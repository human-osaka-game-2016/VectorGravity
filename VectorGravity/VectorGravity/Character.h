/**
* @file		Charcter.h
* @breif	全てのキャラクターの親クラスヘッダ
* @author	shibata
*/

#ifndef CHARCTER_H
#define CHARCTER_H

class Texture;

#define CHARACTER_SIZE 128.0f
#define MOVE_SPEED 10

class Character
{
public:

	Character();
	virtual ~Character();

	virtual void Control() = 0;
	virtual void Draw() = 0;

protected:

	Texture*	m_pTexture;
	float		m_posX;
	float		m_posY;
	bool		m_isDeath;
};

#endif // !CHARCTER_H


