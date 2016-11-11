/**
 * @file Charcter.h
 * @breif 全てのキャラクターの親クラスヘッダー
 * @author shibata
 */

#ifndef CHARCTER_H
#define CHARCTER_H

#include <DirectDrawTexture.h>

#define CHARACTER_SIZE 128.0f
#define MOVE_SPEED 10

class Character
{
public:

	Character();
	virtual ~Character();

	virtual void Control() = 0;
	virtual void Draw() = 0;
	virtual void Attack() = 0;
	virtual void Move() = 0;

protected:

	Texture m_texture;
	float m_posX;
	float m_posY;
};

#endif // !CHARCTER_H


