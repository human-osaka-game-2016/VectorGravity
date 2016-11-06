/**
* @file DirectDrawTexture.h
* @breif テクスチャを描画するための
*/


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

	LPDIRECT3DTEXTURE9 m_pTexture;	//!< テクスチャオブジェクトのポインタ
	IDirect3DDevice9* m_pD3Device;	//!< DirectXのデバイスのポインタ

public:

	Texture();
	~Texture();

	/// テクスチャを画面に張り付ける
	/**
	* @attention これだけでは画面に映らない
	* @param [in] _setdraw はりつける画像の座標サイズ
	*/
	void SetTexture(CUSTOMVERTEX _setdraw[]);

	/// 画像読み込み
	/**
	* 簡単な画像の読み込み
	* @param [in] _filePath[] 読み込む画像の名前
	* @retval S_OK		読み込む成功
	* @retval E_FAIL	読み込み失敗
	*/
	HRESULT LoadTexture(const char _filePath[]);

	/// 画像読み込み
	/**
	* 詳細な画像の読み込み
	* @param [in] _filePath[] 読み込む画像の名前
	* @param [in] _alpha 読み込む画像のアルファの値
	* @param [in] _red 読み込む画像の赤の値
	* @param [in] _green 読み込む画像の緑の値
	* @param [in] _bule 読み込む画像の青の値
	* @retval S_OK		
	* @retval E_FAIL	
	*/
	HRESULT LoadTextureEX(const char _filePath[], int _alpha, int _red, int _green, int _blue);

	/// テクスチャオブジェクトの解放
	/**
	* @retrun なし
	*/
	void Release();

	//LPDIRECT3DTEXTURE9 Get() { return m_pTexture; }

};

#endif