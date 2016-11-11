#include "NormalBullet.h"

NormalBullet::NormalBullet() : 
m_pInputKey(&InputKeyBorad::GetInstance())
{
	m_texture.LoadTexture("Resource/Texture/bekutoru_Shoot.png");
	m_normalBulletRect = { 128, 590, 160,  620};
}

NormalBullet::~NormalBullet()
{

}

void NormalBullet::Control()
{

	Attack();
}

void NormalBullet::Draw()
{
		CUSTOMVERTEX normalBullet[4]
		{
			{ m_normalBulletRect.left, m_normalBulletRect.top, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f},
			{ m_normalBulletRect.right, m_normalBulletRect.top, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
			{ m_normalBulletRect.right, m_normalBulletRect.bottom, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
			{ m_normalBulletRect.left, m_normalBulletRect.bottom, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
		};

		m_texture.SetTexture(normalBullet);
}

void NormalBullet::Attack()
{

	m_normalBulletRect.right += 10;
	m_normalBulletRect.left += 10;

}