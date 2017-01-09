/**
 * @file	MenuButton.h
 * @breif	メニューボタンのクラスヘッダ
 * @author	shibata
 */

#ifndef MENUBUTTON_H
#define MENUBUTTON_H

class Texture;
class Vertex;
class InputKey;
class InputContlloer;

class MenuButton
{
public:

	MenuButton();
	~MenuButton();

	bool Control();
	void Draw();

private:

	InputKey*			m_pInputKey;
	InputContlloer*		m_pInputContlloer;
	Texture*			m_pButtonTexture;
	Vertex*				m_pButtonVertex;

	const float m_kButtonWidth;
	const float m_kButtonHeight;
	const float m_kButtonPosX;
	const float m_kButtonPosY;

};

#endif // !MENUBUTTON_H