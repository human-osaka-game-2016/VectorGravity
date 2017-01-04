/**
* @file		UiManager.h
* @breif	Uiを管理するクラスヘッダ
* @author	shibata
*/

#ifndef UIMANAGER_H
#define UIMANAGER_H

class VectorIcon;
class Gauge;

class UiManager
{
public:

	UiManager();
	~UiManager();

	void Draw();

private:

	VectorIcon* m_pVectorIcon;
	Gauge*		m_pGauge;
};

#endif // !UIMANAGER_H