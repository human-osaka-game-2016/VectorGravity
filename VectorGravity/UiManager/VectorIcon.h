/**
 * @file VectorIcon.h
 * @breif ベクトルアイコンのクラスヘッダー
 * @author shibata
 */

#ifndef VECTORICON_H
#define VECTORICON_H

#include <DirectDrawTexture.h>
#include "Ui.h"

#include "../CharacterManager/Player.h"


class StateManager;

class VectorIcon : public Ui
{
public:

	VectorIcon();
	~VectorIcon();

	virtual void Control();
	virtual void Draw();

private:

	Texture m_texture;
	VectorDirection m_vectorDirection;
	StateManager* m_pStateManager;
	RECT m_vecrotIcon;

};

#endif // !VECTORICON_H

