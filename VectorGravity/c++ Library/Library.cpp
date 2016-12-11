/**
 * @file	Library.cpp
 * @breif	ライブラリを統括しているクラス実装内部
 * @author	shibata
 */

#include "Library.h"
#include "WindowCreate.h"
#include "GraphicsDevice.h"
#include "TextureManager.h"
#include "Font.h"
#include "InputDevice.h"
#include "InputKey.h"
#include "InputContlloer.h"
#include "Sound.h"
#include "Vertex.h"

Library::Library(): 
m_pWindowCreate(NULL),
m_pGraphicsDevice(NULL),
m_pTextureManager(NULL),
m_pVertex(NULL),
m_pFont(NULL),
m_pInputDevice(NULL),
m_pInputKey(NULL),
m_pInputContlloer(NULL),
m_pSound(NULL)
{

}

Library::~Library()
{
	delete m_pWindowCreate;
	delete m_pTextureManager;
	delete m_pVertex;
	delete m_pFont;
	delete m_pInputKey;
	delete m_pInputContlloer;
}

void Library::Initlibrary(HINSTANCE hinstance_, LRESULT CALLBACK WindowProc_(HWND, UINT, WPARAM, LPARAM), TCHAR* titlename_, int clientwidth_, int clientheiht_, bool isfullscreen_)
{
	m_pWindowCreate = new WindowCreate;
	m_pWindowCreate->Create(hinstance_, WindowProc_, titlename_, clientwidth_, clientheiht_, isfullscreen_);

	m_pGraphicsDevice = &GraphicsDevice::Instance();
	m_pGraphicsDevice->InitDirect(m_pWindowCreate->GetHwnd(), clientwidth_, clientheiht_, isfullscreen_);

	m_pInputDevice = &InputDevice::Instance();
	m_pInputDevice->InitInput();
	m_pInputDevice->InitInputKey(m_pWindowCreate->GetHwnd());

	m_pTextureManager = new TextureManager;
	m_pVertex = new Vertex;
	m_pFont = new Font;
	m_pInputKey = new InputKey;

}

void Library::SetFVF(DWORD fvf_)
{
	m_pGraphicsDevice->SetFVF(fvf_);
}

void Library::DrawStart()
{
	m_pGraphicsDevice->DrawStart();
}

void Library::DrawEnd()
{
	m_pGraphicsDevice->DrawEnd();
}

void Library::LoadTexture(int index_, const char* filepath_)
{
	m_pTextureManager->LoadTexture(index_, filepath_);
}

void Library::LoadTextureEX(int index_, const char* filepath_, int alpha_, int red_, int green_, int blue_, bool texsize_)
{
	m_pTextureManager->LoadTextureEX(index_, filepath_, alpha_, red_, green_, blue_, texsize_);
}

void Library::SetTextureSize(float width_, float height_, float maxtu_, float maxtv_, float mintu_, float mintv_)
{
	m_pVertex->SetTextureSize(width_, height_, maxtu_, maxtv_, mintu_, mintv_);
}

void Library::DrawLeftTop(float posx_, float posy_, int index_)
{
	m_pVertex->DrawLeftTop(posx_, posy_, m_pTextureManager->GetTextureData(index_));
}

void Library::DrawCenter(float posx_, float posy_, int index_)
{
	m_pVertex->DrawCenter(posx_, posy_, m_pTextureManager->GetTextureData(index_));
}

void Library::SetFontState(INT heiht_, UINT widht_)
{
	m_pFont->SetFontState(heiht_, widht_);
}

void Library::DrawFont(const char* pstring_, D3DXVECTOR2 pos_, DWORD format_, int red_, int green_, int blue_)
{
	m_pFont->DrawFont(pstring_, pos_, format_, red_, green_, blue_);
}

void Library::GetInputState()
{
	m_pInputKey->GetKeyBoradState();
}

void Library::CheckKey(int dik_, KeyKind set_)
{
	m_pInputKey->CheckKey(dik_, set_);
}

void Library::InitSound(HWND hWnd_)
{
	m_pSound->InitSound(hWnd_);
}

void Library::LoadSoundFile(TCHAR* filepath_)
{
	m_pSound->LoadSoundFile(filepath_);
}

//void Library::SoundState()
//{
//	m_pSound->SoundState();
//}