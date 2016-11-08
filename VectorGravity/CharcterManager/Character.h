/**
 * @file Charcter.h
 * @breif 全てのキャラクターの親クラスヘッダー
 * @author shibata
 */

#ifndef CHARCTER_H
#define CHARCTER_H

#include <DirectDrawTexture.h>


class Character
{
public:
	Character();
	virtual ~Character();

	virtual void Control() = 0;
	virtual void Draw() = 0;
	virtual void Attack() = 0;
	virtual void Move() = 0;
};

#endif // !CHARCTER_H


