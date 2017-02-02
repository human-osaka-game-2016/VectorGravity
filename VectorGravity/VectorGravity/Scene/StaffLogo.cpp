#include <Texture.h>
#include <Vertex.h>
#include "StaffLogo.h"

StaffLogo::StaffLogo() :
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_fadeLogoTime(NULL),
m_LogoAlpha(NULL),
m_kStaffLogoWidht(1024.0f),
m_kStaffLogoHeight(450.0f),
m_kStaffLogoPosX(135.0f),
m_kStaffLogoPosY(150.0f)
{
	m_pTexture->LoadTexture("Resource/Texture/staffroll.png");
	m_pVertex->SetTextureSize(m_kStaffLogoWidht, m_kStaffLogoHeight);
}

StaffLogo::~StaffLogo()
{
	delete m_pTexture;
	delete m_pVertex;
}

void StaffLogo::Control()
{
	if (m_LogoAlpha < 255)
	{
		Fade();
	}
}

void StaffLogo::Draw()
{
	DWORD logoColor = m_pVertex->AppointColor(m_LogoAlpha);
	m_pVertex->SetColor(logoColor);

	m_pVertex->DrawLeftTop(m_kStaffLogoPosX, m_kStaffLogoPosY, m_pTexture);
}

void StaffLogo::Fade()
{
	m_fadeLogoTime++;

	if (m_fadeLogoTime > 30)
	{
		m_LogoAlpha += 3;
	}
}