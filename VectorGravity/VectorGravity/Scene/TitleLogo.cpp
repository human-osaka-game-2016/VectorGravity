/**
 * @file	TitleLogo.cpp
 * @breif	タイトルロゴのクラス実装
 * @author	shibata
 */

#include "TitleLogo.h"
#include <Texture.h>
#include <Vertex.h>

TitleLogo::TitleLogo() : 
m_pLogoTexture(new Texture),
m_pLogoVertex(new Vertex),
m_LogoWidth(512),
m_LogoHeight(512),
m_LogoPosX(384),
m_LogoPosY(720),
m_slideCount(0)
{
	m_pLogoTexture->LoadTexture("Resource/Texture/TitleLogo.png");
	m_pLogoVertex->SetTextureSize(m_LogoWidth, m_LogoHeight);
}

TitleLogo::~TitleLogo()
{
	delete m_pLogoVertex;
	delete m_pLogoTexture;
}

void TitleLogo::Draw()
{
	m_slideCount++;
	if (m_slideCount > 30)
	{
		if (m_LogoPosY > 30)
		{
			m_LogoPosY -= 25;
		}
	}
	m_pLogoVertex->DrawLeftTop(m_LogoPosX, m_LogoPosY, m_pLogoTexture);
}