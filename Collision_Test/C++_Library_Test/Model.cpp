#include "Model.h"

Model::Model() : 
m_graphicsdevice(&GraphicsDevice::getInstance()),
m_inputkeydevice(&InputKeyBorad::GetInstance())
{

}

Model::~Model()
{
}

bool Model::Run()
{

	Render();
	Control();

	return true;

}

void Model::Control()
{
	m_inputkeydevice->GetKeyBoradState();

	m_inputkeydevice->KeyCheck(DIK_LEFT, LEFT);
	m_inputkeydevice->KeyCheck(DIK_RIGHT, RIGHT);
	m_inputkeydevice->KeyCheck(DIK_UP, UP);
	m_inputkeydevice->KeyCheck(DIK_DOWN, DOWN);


	m_objmanager.Control();
}

void Model::Render()
{
	m_graphicsdevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	m_graphicsdevice->DrawStart();

	m_objmanager.Draw();

	m_graphicsdevice->DrawEnd();
}