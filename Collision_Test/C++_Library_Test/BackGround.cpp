#include "BackGround.h"

BackGround::BackGround() : Obj()
{
	m_texture.LoadTexture("fog.jpg");
}

BackGround::~BackGround()
{

}

void BackGround::Draw()
{
	CUSTOMVERTEX backGround[4]
	{
		{	 0.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	m_texture.SetTexture(backGround);
}