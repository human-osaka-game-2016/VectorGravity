/**
 * @file	Bullet.h
 * @breif	�e�̐e�N���X�w�b�_
 * @author	shibata
 */

#ifndef BULLET_H
#define BULLET_H

class Texture;
class Vertex;

class Bullet
{
public:

	Bullet();
	~Bullet();

	virtual void Control() = 0;
	virtual void Draw() = 0;
	virtual void Attack() = 0;

protected:

	//void Attack();
	Texture*	m_pTexture;
	Vertex*		m_pVertex;

};

#endif // !BULLET_H