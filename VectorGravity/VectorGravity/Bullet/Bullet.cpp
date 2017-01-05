/**
 * @file	Bullet.cpp
 * @breif	íeÇÃêeÉNÉâÉXé¿ëï
 * @author	shibata
 */

#include "Bullet.h"
#include <Texture.h>

Bullet::Bullet():
m_pTexture(new Texture),
m_pTexture2(new Texture)
{
	m_pTexture->LoadTexture("Resource/Texture/PlayerBullet.png");
	m_pTexture2->LoadTexture("Resource/Texture/EnemyBullet.png");
}

Bullet::~Bullet()
{
	delete m_pTexture;
	delete m_pTexture2;
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