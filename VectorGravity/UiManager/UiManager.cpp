#include "UiManager.h"
#include "Ui.h"
#include "VectorIcon.h"

UiManager::UiManager() : 
m_pVectorIcon(new VectorIcon)
{

}

UiManager::~UiManager()
{
	delete m_pVectorIcon;
}

void UiManager::Control()
{
	Ui* UiControlList[1]
	{
		m_pVectorIcon
	};

	for (int i = 0; i < 1; i++)
	{
		UiControlList[i]->Control();
	}
}

void UiManager::Draw()
{

	Ui* UiDrawList[1]
	{
		m_pVectorIcon
	};

	for (int i = 0; i < 1; i++)
	{
		UiDrawList[i]->Draw();
	}
}