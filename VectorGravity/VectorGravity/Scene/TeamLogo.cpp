/**
 * @file	TeamLogo.cpp
 * @breif	チームロゴのクラス実装
 * @author	shibata
 */

#include "TeamLogo.h"
#include <Texture.h>
#include <Vertex.h>

TeamLogo::TeamLogo() : 
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_alpha(NULL),
m_logoState(FADE_IN),
m_startTimer(NULL)
{
	m_pTexture->LoadTexture("Resource/Texture/TeamLogo.png");
	m_pVertex->SetTextureSize(LOGO_WIDTH, LOGO_HEIGHT);
}

TeamLogo::~TeamLogo()
{
	delete m_pTexture;
	delete m_pVertex;
}

bool TeamLogo::Control()
{
	bool sceneTranser = false;

	m_startTimer++;
	if (m_startTimer > LOGO_START_SECOND)
	{
		if (Fade())
		{
			sceneTranser = true;
		}
		else
		{
			sceneTranser = false;
		}
	}

	return sceneTranser;
}

void TeamLogo::Draw()
{
	DWORD color = m_pVertex->AppointColor(m_alpha);
	m_pVertex->SetColor(color);

	m_pVertex->DrawCenter(LOGO_POSITIONX, LOGO_POSITIONY, m_pTexture);
}

bool TeamLogo::Fade()
{
	bool FadeFinish = false;

	switch (m_logoState)
	{
	case TeamLogo::FADE_IN:

		if (m_alpha < ALPHA_MAX)
		{
			m_alpha += 3;
		}
		else
		{
			m_logoState = FADE_OUT;
		}

		break;
	case TeamLogo::FADE_OUT:

		if (m_alpha > NULL)
		{
			m_alpha -= 3;
		}
		else
		{
			FadeFinish = true;
			m_logoState = FADE_IN;
		}

		break;
	}

	return FadeFinish;
}