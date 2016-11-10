/**
 * @file Bullet.h
 * @breif �e�̐e�N���X�w�b�_�[
 * @author shibata
 */

#ifndef BULLET_H
#define BULLET_H

#include <DirectDrawTexture.h>

class Bullet
{
public:

	Bullet();
	~Bullet();

	virtual void Control() = 0;
	virtual void Draw() = 0;
	virtual void Attack() = 0;

protected:

	Texture m_texture;

};

#endif // !BULLET_H
