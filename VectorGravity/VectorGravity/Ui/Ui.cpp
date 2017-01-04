/**
 * @file	Ui
 * @breif	Uiの親クラスヘッダ
 * @author	shibata
 */

#include "Ui.h"
#include <Texture.h>
#include <Vertex.h>
#include "../StateManager/StateManager.h"

Ui::Ui() : 
m_pTexture(new Texture),
m_pVertex(new Vertex),
m_pStateManager(&StateManager::Instance())
{

}

Ui::~Ui()
{

}

void Ui::Draw()
{

}