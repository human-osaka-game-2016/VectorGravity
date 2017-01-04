/**
* @file		UiManager.h
* @breif	Ui���Ǘ�����N���X�w�b�_
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