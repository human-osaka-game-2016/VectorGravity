/**
 * @file	Bullet.h
 * @breif	弾の親クラスヘッダ
 * @author	shibata
 */

#ifndef BULLET_H
#define BULLET_H

class Bullet
{
public:

	Bullet();
	~Bullet();

	virtual void Control() = 0;
	virtual void Draw() = 0;

protected:

	void Attack();

};

#endif // !BULLET_H