/**
 * @file	Bullet.h
 * @breif	弾の親クラスヘッダ
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
	virtual ~Bullet();

	virtual void Control() = 0;
	virtual void Draw() = 0;
	virtual void Attack() = 0;

protected:

	//void Attack();
	Texture*	m_pTexture;
	Texture*	m_pTexture2;
	Vertex*		m_pVertex;
	Vertex*		m_pVertex2;

};

#endif // !BULLET_H