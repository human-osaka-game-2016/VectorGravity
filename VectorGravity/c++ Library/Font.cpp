/**
 * @file	Font.cpp
 * @breif	フォントクラスの実装内部
 * @author	shibata
 */

#include "Font.h"

Font::Font() : 
m_pD3Device(GraphicsDevice::Instance().GetDevice()),
m_pFont(NULL)
{

}

Font::~Font()
{
	if (m_pFont != NULL)
	{
		m_pFont->Release();
	}
}

HRESULT Font::SetFontState(INT heiht_, UINT widht_)
{
	if (FAILED(D3DXCreateFont(
		m_pD3Device,
		heiht_,
		widht_,
		FW_REGULAR,
		NULL,
		FALSE,
		SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		PROOF_QUALITY,
		FIXED_PITCH | FF_MODERN,
		TEXT("ＭＳ　Ｐゴシック"),
		&m_pFont)))

	{
		MessageBox(NULL, "設定ができません", NULL, MB_OK);

		return E_FAIL;
	}

	return S_OK;
}

void Font::DrawFont(const char* pstring_, D3DXVECTOR2 pos_, DWORD format_, int red_, int green_, int blue_)
{
	RECT rect;
	D3DXFONT_DESC desc;

	m_pFont->GetDesc(&desc);

	rect.left = (LONG)pos_.x;
	rect.top = (LONG)pos_.y;
	rect.right = (LONG)pos_.x + desc.Width * strlen(pstring_);
	rect.bottom = (LONG)pos_.y + desc.Height * strlen(pstring_);

	m_pFont->DrawText(
		NULL,
		pstring_,
		-1,
		&rect,
		format_,
		D3DCOLOR_XRGB(red_, green_, blue_)
		);
}