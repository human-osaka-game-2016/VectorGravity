/**
 * @file	GraphicsDevice.cpp
 * @breif	DirectXのインターフェイスとグラフィックデバイスの生成クラス実装内部
 * @author	shibata
 */

#include "GraphicsDevice.h"

GraphicsDevice::~GraphicsDevice()
{
	if (m_pD3Device != NULL)
	{
		m_pD3Device->Release();
		m_pD3Device = NULL;
	}

	if (m_pDirect3D != NULL)
	{
		m_pDirect3D->Release();
		m_pDirect3D = NULL;
	}
}


bool GraphicsDevice::InitDirect(HWND hWnd_, int width_, int heiht_, bool isfullscreen_)
{
	m_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (m_pDirect3D == NULL)
	{
		MessageBox(NULL, "オブジェクトが生成できませんでした。", NULL, MB_OK);

		return false;
	}

	m_pDirect3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &m_d3ddm);


	ZeroMemory(&m_d3dppFull, sizeof(D3DPRESENT_PARAMETERS));
	m_d3dppFull.BackBufferWidth = width_;
	m_d3dppFull.BackBufferHeight = heiht_;
	m_d3dppFull.BackBufferFormat = m_d3ddm.Format;
	m_d3dppFull.BackBufferCount = 1;
	m_d3dppFull.SwapEffect = D3DSWAPEFFECT_DISCARD;
	m_d3dppFull.hDeviceWindow = hWnd_;
	m_d3dppFull.Windowed = FALSE;
	m_d3dppFull.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;

	ZeroMemory(&m_d3dppWindow, sizeof(D3DPRESENT_PARAMETERS));
	m_d3dppWindow.BackBufferFormat = m_d3ddm.Format;
	m_d3dppWindow.BackBufferCount = 1;
	m_d3dppWindow.SwapEffect = D3DSWAPEFFECT_DISCARD;
	m_d3dppWindow.Windowed = TRUE;

	ZeroMemory(&m_d3dpp, sizeof(D3DPRESENT_PARAMETERS));
	if (isfullscreen_)
	{
		m_d3dpp = m_d3dppFull;
	}
	else
	{
		m_d3dpp = m_d3dppWindow;
	}

	m_pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd_,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&m_d3dpp,
		&m_pD3Device);

	if (m_pD3Device == NULL)
	{
		MessageBox(NULL, "デバイスが生成できませんでした。", NULL, MB_OK);

		m_pDirect3D->Release();

		return false;
	}

	InitDraw();

	return true;
}

void GraphicsDevice::InitDraw()
{
	m_pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);					
	m_pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);				
	m_pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	m_pD3Device->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	m_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	m_pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	m_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	m_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	m_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}

void GraphicsDevice::SetFVF(DWORD fvf_)
{
	m_pD3Device->SetFVF(fvf_);
}

void GraphicsDevice::DrawStart()
{
	m_pD3Device->Clear(0, NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00)
		, 1.0, 0);

	m_pD3Device->BeginScene();
}

void GraphicsDevice::DrawEnd()
{
	m_pD3Device->EndScene();

	m_pD3Device->Present(NULL, NULL, NULL, NULL);

}