#include "Pausebackground.h"
#include <Texture.h>
#include <Vertex.h>

PauseBackground::PauseBackground() :
m_pTexture(new Texture),
m_pVertex(new Vertex)
{
	m_pTexture->LoadTexture("Resource/Texture/PauseBackground.png");
	m_pVertex->SetTextureSize(1280.0f, 720.0f);
}

PauseBackground::~PauseBackground()
{
	delete m_pTexture;
	delete m_pVertex;
}

void PauseBackground::Draw()
{
	DWORD pauseColor = m_pVertex->AppointColor(180);
	m_pVertex->SetColor(pauseColor);

	m_pVertex->DrawLeftTop(0.0f, 0.0f, m_pTexture);
}