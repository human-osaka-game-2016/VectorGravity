/**
* @file GraphicsDevice.cpp
* @breif 初期化の処理の内容
*/

#include "GraphicsDevice.h"

#pragma comment(lib, "d3dx9.lib")

GraphicsDevice::GraphicsDevice()
{
	m_pDirect3D = NULL;
	m_pD3Device = NULL;
}

// DirectXの初期化
bool GraphicsDevice::InitDirect(HWND _hWnd)
{
	m_hWnd = _hWnd;

	// DirectXオブジェクトの生成
	m_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	// オブジェクトが生成できているかのチェック
	if (m_pDirect3D == NULL)
	{
		MessageBox(NULL, "オブジェクトが生成できませんでした。", NULL, MB_OK);

		return false;
	}

	// d3dppのメモリを空にしている
	ZeroMemory(&m_d3dpp, sizeof(m_d3dpp));

	// 空にしてからデータを入れている
		m_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
		m_d3dpp.BackBufferCount = 1;
		m_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		m_d3dpp.Windowed = TRUE;
		m_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	// DirectXのデバイスを生成
	m_pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		m_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&m_d3dpp,
		&m_pD3Device);

	// デバイスが生成できているかのチェック
	if (m_pD3Device == NULL)
	{
		MessageBox(NULL, "デバイスが生成できませんでした。", NULL, MB_OK);

		// デバイスが生成できていなければオブジェクトを解放
		m_pDirect3D->Release();

		return false;
	}

	// 最後にテクスチャの初期化をしている
	InitDraw();

	return true;

}

// テクスチャの初期化をしている
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

// 柔軟な頂点フォーマットを設定する
void GraphicsDevice::SetFVF(DWORD _fvf)
{
	m_pD3Device->SetFVF(_fvf);
}

// 描画を始めるために必要
void GraphicsDevice::DrawStart()
{
	m_pD3Device->Clear(0, NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00)
		, 1.0, 0);

	m_pD3Device->BeginScene();
}

// 描画の終わりに必要
void GraphicsDevice::DrawEnd()
{
	m_pD3Device->EndScene();

	// もしデバイスがロストされていたらこの処理の中に入る
	if (m_pD3Device->Present(NULL, NULL, NULL, NULL) == D3DERR_DEVICELOST)
	{
		DeviceLost();
	}
}

// デバイスをロストしたときの必要な処理
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

// もう1回デバイスを取得する
void GraphicsDevice::ResetDevice()
{
	if (m_pD3Device->Reset(&m_d3dpp) != D3D_OK)
	{
		PostQuitMessage(0);

		return;
	}
}

// デバイスが欲しいときに使用する
IDirect3DDevice9* GraphicsDevice::GetDevice()
{
	return m_pD3Device;
}