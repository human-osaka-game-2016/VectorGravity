#ifndef DRAWTEXTURE
#define DRAWTEXTURE

#include "GraphicsDevice.h"


struct CUSTOMVERTEX
{
	FLOAT x, y, z, rhw;
	DWORD color;
	FLOAT tu, tv;
};

class Texture
{
private:

	LPDIRECT3DTEXTURE9 m_pTexture;
	IDirect3DDevice9* m_pD3Device;

public:

	Texture();
	~Texture();
	void SetTexture(CUSTOMVERTEX _setdraw[]);
	HRESULT LoadTexture(const char _filePath[]);
	HRESULT LoadTextureEX(const char _filePath[], int ƒ¿, int red, int green, int blue);
	void Release();

	//LPDIRECT3DTEXTURE9 Get() { return m_pTexture; }

};

#endif