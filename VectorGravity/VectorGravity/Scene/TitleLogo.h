/**
 * @file	TitleLogo.h
 * @breif	タイトルロゴのクラスヘッダ
 * @author	shibata
 */

#ifndef TITLELOGO_H
#define TITLELOGO_H

class TitleLogo
{
public:

	TitleLogo();
	~TitleLogo();

	void Control();
	void Draw();

private:

	void SlideIn();
};

#endif // !TITLELOGO_H