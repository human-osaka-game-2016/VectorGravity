#include <Texture.h>
#include <Vertex.h>
#include "CreditLogo.h"

CreditLogo::CreditLogo() :
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_fadeStartTimer(NULL),
m_LogoAlpha(NULL),
m_kLogoWidth(1024.0f),
m_kLogoHeight(128.0f),
m_kLogoPosX(640.0f),
m_kLogoPosY(100.0f)
{
	m_pTexture->LoadTexture("Resource/Texture/CreditLogo.png");
	m_pVertex->SetTextureSize(m_kLogoWidth, m_kLogoHeight);
}

CreditLogo::~CreditLogo()
{
	delete m_pTexture;
	delete m_pVertex;
}

void CreditLogo::Control()
{
	if (m_LogoAlpha < 255)
	{
		Fade();
	}
}

void CreditLogo::Draw()
{
	DWORD logoColor = m_pVertex->AppointColor(m_LogoAlpha);
	m_pVertex->SetColor(logoColor);

	m_pVertex->DrawCenter(m_kLogoPosX, m_kLogoPosY, m_pTexture);
}

void CreditLogo::Fade()
{
	m_fadeStartTimer++;

	if (m_fadeStartTimer > 30)
	{
		m_LogoAlpha += 3;
	}
}