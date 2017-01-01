/**
 * @file	Bullet.cpp
 * @breif	弾の親クラス実装
 * @author	shibata
 */

#include "Bullet.h"
#include <Texture.h>

Bullet::Bullet():
m_pTexture(new Texture)
{
	m_pTexture->LoadTexture("Resource/Texture/PlayerBullet.png");
}

Bullet::~Bullet()
{
	delete m_pTexture;
}

void Bullet::Control()
{
	//Attack();
}

void Bullet::Draw()
{

}

void Bullet::Attack()
{

}