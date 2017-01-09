#include <Texture.h>
#include <Vertex.h>
#include "PauseLogo.h"

PauseLogo::PauseLogo() :
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_kLogoWidth(1024.0f),
m_kLogoHeight(128.0f),
m_kLogoPosX(640.0f),
m_kLogoPosY(180.0f)
{
	m_pTexture->LoadTexture("Resource/Texture/PauseLogo.png");
	m_pVertex->SetTextureSize(m_kLogoWidth, m_kLogoHeight);
}

PauseLogo::~PauseLogo()
{
	delete m_pTexture;
	delete m_pVertex;
}

void PauseLogo::Control()
{

}

void PauseLogo::Draw()
{
	m_pVertex->DrawCenter(m_kLogoPosX, m_kLogoPosY, m_pTexture);
}