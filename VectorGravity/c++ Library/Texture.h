/**
 * @file	Texture.h
 * @breif	テクスチャの読み込みクラスヘッダ
 * @author	shibata
 */

#ifndef DRAWTEXTURE_H
#define DRAWTEXTURE_H

#include "GraphicsDevice.h"

class Texture
{
public:

	/**
	 * コンストラクタ
	 */
	Texture();

	/**
	 * デストラクタ
	 */
	~Texture();

	/**
	 * 画像の読み込み
	 * @param  [in]	filepath_	画像ファイルのパス
	 * @retval		S_OK		画像の読み込み成功
	 * @retval		E_FAIL		画像の読み込み失敗
	 */
	HRESULT LoadTexture(const char* filepath_);

	/**
	 * 詳細な画像の読み込み
	 * @param [in]	filepath_	画像ファイルのパス
	 * @param [in]	alpha_		画像の透過値		デフォルトは255
	 * @param [in]	red_		画像のR値			デフォルトは0	
	 * @param [in]	green_		画像のG値			デフォルトは0
	 * @param [in]	blue_		画像のB値			デフォルトは0
	 * @param [in]	istexsize_	2の累乗かどうか	デフォルトはtrue	
	 * @retval		S_OK		画像の読み込み成功
	 * @retval		E_FAIL		画像の読み込み失敗
	 */
	HRESULT LoadTextureEX(const char* filepath_, int alpha_ = 255, int red_ = 0, int green_ = 0, int blue_ = 0, bool texsize_ = true);

	/**
	 * @todo 名前が微妙なので変更の可能性あり
	 * テクスチャデータの情報取得関数
	 * @return m_pTexture
	 */
	LPDIRECT3DTEXTURE9 Texture::GetTextureData()
	{
		return m_pTexture;
	}

private:

	LPDIRECT3DTEXTURE9	m_pTexture;		//!< DirectXのテクスチャインターフェイス
	LPDIRECT3DDEVICE9	m_pD3Device;	//!< DirectXのデバイス

};

#endif // !DRAWTEXTURE_H