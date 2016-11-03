#include "DirectDrawTexture.h"
#include "GraphicsDevice.h"

/* : 以降はメンバイニシャライザと言うものです。
わからない人は調べてください
*/
Texture::Texture() : m_pTexture(NULL), m_pD3Device(GraphicsDevice::GetInstance().GetDevice())
{

}

// デストラクタなので使ったものを解放している
Texture::~Texture()
{
	Release();
}

// テクスチャを画面に張り付ける
void Texture::SetTexture(CUSTOMVERTEX _setdraw[])
{
	m_pD3Device->SetTexture(0, m_pTexture);

	m_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2,
		_setdraw, sizeof(CUSTOMVERTEX));
}

// 引数の名前の画像を読み込む
HRESULT Texture::LoadTexture(const char _filePath[])
{
	if (FAILED(D3DXCreateTextureFromFile(m_pD3Device, _filePath, &m_pTexture)))
	{
		MessageBox(NULL, "画像が読み込めませんでした。", NULL, MB_OK);

		return E_FAIL;
	}

	return S_OK;
}

// テクスチャオブジェクトを解放している
void Texture::Release()
{
	m_pTexture->Release();
}