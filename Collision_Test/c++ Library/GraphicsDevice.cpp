#include "GraphicsDevice.h"

#pragma comment(lib, "d3dx9.lib")

bool GraphicsDevice::InitDirect(HWND _hWnd)
{
	m_hWnd = _hWnd;

	m_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (m_pDirect3D == NULL)
	{
		MessageBox(NULL, "オブジェクトが生成できませんでした。", NULL, MB_OK);

		return false;
	}

	ZeroMemory(&m_d3dpp, sizeof(m_d3dpp));

		m_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
		m_d3dpp.BackBufferCount = 1;
		m_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		m_d3dpp.Windowed = TRUE;
		m_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	
	m_pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		m_hWnd,
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

void GraphicsDevice::SetFVF(DWORD _fvf)
{
	m_pD3Device->SetFVF(_fvf);
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

	if (m_pD3Device->Present(NULL, NULL, NULL, NULL) == D3DERR_DEVICELOST)
	{
		DeviceLost();
	}
}

bool GraphicsDevice::DeviceLost()
{
	HRESULT wrh = m_pD3Device->TestCooperativeLevel();

	if (wrh == D3D_OK)
	{
		return true;
	}

	if (wrh != D3DERR_DEVICENOTRESET)
	{
		return false;
	}

	ResetDevice();

	return true;

}

void GraphicsDevice::ResetDevice()
{
	if (m_pD3Device->Reset(&m_d3dpp) != D3D_OK)
	{
		PostQuitMessage(0);

		return;
	}
}

IDirect3DDevice9* GraphicsDevice::GetDevice()
{
	return m_pD3Device;
}