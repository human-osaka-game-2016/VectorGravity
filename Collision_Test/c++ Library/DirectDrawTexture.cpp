#include "DirectDrawTexture.h"
#include "GraphicsDevice.h"

Texture::Texture() : m_pTexture(NULL), m_pD3Device(GraphicsDevice::getInstance().GetDevice())
{

}

Texture::~Texture()
{
	Release();
}

void Texture::SetTexture(CUSTOMVERTEX _setdraw[])
{
	m_pD3Device->SetTexture(0, m_pTexture);

	m_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2,
		_setdraw, sizeof(CUSTOMVERTEX));
}

HRESULT Texture::LoadTexture(const char _filePath[])
{
	if (FAILED(D3DXCreateTextureFromFile(m_pD3Device, _filePath, &m_pTexture)))
	{
		MessageBox(NULL, "‰æ‘œ‚ª“Ç‚Ýž‚ß‚Ü‚¹‚ñ‚Å‚µ‚½B", NULL, MB_OK);

		return E_FAIL;
	}

	return S_OK;
}

void Texture::Release()
{
	m_pTexture->Release();
}