#ifndef GRAPHICSDEVICE
#define GRAPHICSDEVICE

#include <d3dx9.h>

class GraphicsDevice
{
private:


	GraphicsDevice(){}

	IDirect3D9*	m_pDirect3D;
	IDirect3DDevice9* m_pD3Device;
	D3DPRESENT_PARAMETERS	m_d3dpp;
	HWND m_hWnd;

public:

	static GraphicsDevice& GetInstance()
	{
		static GraphicsDevice graphicsDevice;
		
		return graphicsDevice;
	}

	bool InitDirect(HWND _hWnd);
	void InitDraw();
	void SetFVF(DWORD _fvf);
	void DrawStart();
	void DrawEnd();
	bool DeviceLost();
	void ResetDevice();
	
	IDirect3DDevice9* GetDevice();

};


#endif