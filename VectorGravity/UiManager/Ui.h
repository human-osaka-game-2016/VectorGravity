/**
 * @file Ui.h
 * @breif Uiの親クラスヘッダー
 * @author shibata
 */


#ifndef UI_H
#define UI_H

class Ui
{
public:

	Ui();
	virtual ~Ui();

	virtual void Control() = 0;
	virtual void Draw() = 0;
};

#endif // !UI_H

