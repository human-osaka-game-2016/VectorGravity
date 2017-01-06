#include "Gauge.h"
#include <Texture.h>
#include <Vertex.h>
#include "../StateManager/StateManager.h"

Gauge::Gauge() : 
m_gaugeWidth(320.0f),
m_gaugeHeight(64.0f),
m_hpFlamePosX(128.0f),
m_hpFlamePosY(32.0f),
m_gpFlamePosX(128.0f),
m_gpFlamePosY(96.0f),
m_hpGaugePosX(138.0f),
m_hpGaugePosY(31.85f),
m_gpGaugePosX(138.0f),
m_gpGaugePosY(96.0f),
m_hpGaugeWidth(300.5f),
m_hpGaugeHeight(64.0f),
m_gpGaugeWidth(300.5f),
m_gpGaugeHeight(64.0f)
{
	m_pTexture->LoadTexture("Resource/Texture/Gauge.png");
}

Gauge::~Gauge()
{
	delete m_pTexture;
	delete m_pVertex;

}

void Gauge::Draw()
{
	DrawFrame();
	DrawHp();
	DrawGp();
}

void Gauge::DrawFrame()
{
	m_pVertex->SetTextureSize(m_gaugeWidth, m_gaugeHeight, 1.0f, 0.2f, 0.0f, 0.0f);
	m_pVertex->DrawLeftTop(m_hpFlamePosX, m_hpFlamePosY, m_pTexture);
	m_pVertex->DrawLeftTop(m_gpFlamePosX, m_gpFlamePosY, m_pTexture);
}

void Gauge::DrawHp()
{
	m_pVertex->SetTextureSize(m_hpGaugeWidth, m_hpGaugeHeight, 0.96875f, 0.4f, 0.03125f, 0.2f);
	m_pVertex->DrawLeftTop(m_hpGaugePosX, m_hpGaugePosY, m_pTexture);

	m_playerHp = m_pStateManager->GetPlayerHp();

	if (m_playerHp < m_hpGaugeWidth)
	{
		m_hpGaugeWidth--;
	}

}

void Gauge::DrawGp()
{
	m_pVertex->SetTextureSize(m_gpGaugeWidth, m_gpGaugeHeight, 0.96875f, 0.6f, 0.03125f, 0.4f);
	m_pVertex->DrawLeftTop(m_gpGaugePosX, m_gpGaugePosY, m_pTexture);

	m_playerGp = m_pStateManager->GetPlayerGp();

	if (m_playerGp < m_gpGaugeWidth)
	{
		m_gpGaugeWidth--;
	}
	else if (m_playerGp > m_gpGaugeWidth)
	{
		m_gpGaugeWidth++;
	}
}