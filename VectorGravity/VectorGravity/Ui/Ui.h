/**
* @file		Ui.h
* @breif	Uiの親クラスヘッダ
* @author	shibata
*/

#ifndef UI_H
#define UI_H

class Texture;
class Vertex;
class StateManager;

class Ui
{
public:

	Ui();
	virtual ~Ui();

	virtual void Draw() = 0;

protected:

	Texture*		m_pTexture;
	Vertex*			m_pVertex;
	StateManager*	m_pStateManager;
};

#endif // !UI_H