/**
 * @file UiManager.h
 * @breif Uiを管理するクラスのヘッダー
 * @author shibata
 */

#ifndef UIMANAGER_H
#define UIMANAGER_H

class VectorIcon;

class UiManager
{
public:

	UiManager();
	~UiManager();

	void Control();
	void Draw();

private:

	VectorIcon* m_pVectorIcon;
};

#endif // !UIMANAGER_H
