/**
 * @file	UiManager.cpp
 * @breif	Ui‚ğŠÇ—‚·‚éƒNƒ‰ƒXÀ‘•
 * @author	shibata
 */

#include "UiManager.h"
#include "Ui.h"
#include "VectorIcon.h"
#include "Gauge.h"

UiManager::UiManager() :
m_pVectorIcon(new VectorIcon),
m_pGauge(new Gauge)
{

}

UiManager::~UiManager()
{
	delete m_pVectorIcon;
	delete m_pGauge;
}

void UiManager::Draw()
{
	Ui* pUiDraw[2] = { m_pVectorIcon, m_pGauge };

	for (int i = 0; i < 2; i++)
	{
		pUiDraw[i]->Draw();
	}
}