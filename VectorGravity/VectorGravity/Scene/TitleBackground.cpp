/**
 * @file	TitleBackgound.h
 * @breif	�^�C�g���V�[���w�i�̃N���X����
 * @author	shibata
 */

#include "TitleBackground.h"
#include <Texture.h>
#include <Vertex.h>

TitleBackground::TitleBackground() : 
m_pTexture(new Texture),
m_pVertex(new Vertex)
{
	m_pTexture->LoadTexture("Resource/Texture/Title.jpg");
	m_pVertex->SetTextureSize(BACKGROUND_WIDHT, BACKGROUND_HEIGHT);
}

TitleBackground::~TitleBackground()
{
	delete m_pTexture;
	delete m_pVertex;
}

void TitleBackground::Control()
{

}

void TitleBackground::Draw()
{
	m_pVertex->DrawCenter(BACKGROUND_POSITIONX / 2, BACKGROUND_POSITIONY / 2, m_pTexture);
}