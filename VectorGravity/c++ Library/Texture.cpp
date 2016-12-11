/**
 * @file	Texture.cpp
 * @breif	テクスチャの読み込みクラス実装内部
 * @author	shibata
 */

#include "Texture.h"

Texture::Texture() : 
m_pTexture(NULL),
m_pD3Device(GraphicsDevice::Instance().GetDevice())
{

}

Texture::~Texture()
{
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
	}
}

HRESULT Texture::LoadTexture(const char* filepath_)
{
	if (FAILED(D3DXCreateTextureFromFile(m_pD3Device, filepath_, &m_pTexture)))
	{
		MessageBox(NULL, "画像が読み込めませんでした。", NULL, MB_OK);

		return E_FAIL;
	}

	return S_OK;
}

HRESULT Texture::LoadTextureEX(const char* filepath_, int alpha_, int red_, int green_, int blue_, bool texsize_)
{
	if (texsize_)	// 2の累乗なら
	{
		if (FAILED(D3DXCreateTextureFromFileEx(
			m_pD3Device,
			filepath_,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			0,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_FILTER_NONE,
			D3DX_DEFAULT,
			D3DCOLOR_ARGB(alpha_, red_, green_, blue_),
			NULL,
			NULL,
			&m_pTexture
			)))
		{
			MessageBox(0, "画像の読み込みに失敗しました。", NULL, MB_OK);

			return E_FAIL;
		}
	}
	else			// 2の累乗でないのなら
	{
		if (FAILED(D3DXCreateTextureFromFileEx(
			m_pD3Device,
			filepath_,
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT,
			0,
			D3DFMT_UNKNOWN,
			D3DPOOL_MANAGED,
			D3DX_FILTER_NONE,
			D3DX_FILTER_NONE,
			D3DCOLOR_ARGB(alpha_, red_, green_, blue_),
			NULL, 
			NULL,
			&m_pTexture
			)))
		{
			MessageBox(0, "画像の読み込みに失敗しました。", NULL, MB_OK);

			return E_FAIL;
		}

	}

	return S_OK;
}