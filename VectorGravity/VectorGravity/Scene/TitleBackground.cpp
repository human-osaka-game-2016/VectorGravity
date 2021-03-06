/**
 * @file	TitleBackgound.h
 * @breif	タイトルシーン背景のクラス実装
 * @author	shibata
 */

#include "TitleBackground.h"
#include <Texture.h>
#include <Vertex.h>

TitleBackground::TitleBackground() : 
m_pTexture(new Texture),
m_pVertex(new Vertex)
{
	m_pTexture->LoadTexture("Resource/Texture/TitleBackground.png");
	m_pVertex->SetTextureSize(BACKGROUND_WIDHT, BACKGROUND_HEIGHT);
}

TitleBackground::~TitleBackground()
{
	delete m_pTexture;
	delete m_pVertex;
}

void TitleBackground::Draw()
{
	m_pVertex->DrawLeftTop(0.0f, 0.0f, m_pTexture);
}