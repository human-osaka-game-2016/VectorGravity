/**
 * @file	Font.h
 * @breif	フォントクラスヘッダ
 * @author	shibata
 */

#ifndef FONT_H
#define FONT_H

#include "GraphicsDevice.h"

class Font
{
public:

	/*
	 * デフォルトコンストラクタ
	 */
	Font();

	/*
	 * デストラクタ
	 */
	~Font();

	 
	/**
	 * フォントの設定をする
	 * @param [in]	heiht_		文字の高さを決める
	 * @param [in]	widht_		文字の幅を決める
	 * @retval		S_OK		画像の読み込み成功
	 * @retval		E_FAIL		画像の読み込み失敗
	 */
	HRESULT SetFontState(INT heiht_, UINT widht_);

	/**
	 * フォントの描画
	 * @param [in] pstring_	表示する文字列
	 * @param [in] pos_		描画する場所
	 * @param [in] format_	どこ寄せをするか	デフォルトは左寄せ
	 * @param [in] red_		文字のR値			デフォルトは255
	 * @param [in] greeen_	文字のG値			デフォルトは255
	 * @param [in] blue_	文字のB値			デフォルトは255
	 */
	void DrawFont(const char* pstring_, D3DXVECTOR2 pos_, DWORD format_ = DT_LEFT, int red_ = 255, int green_ = 255, int blue_ = 255);

private:

	LPD3DXFONT				m_pFont;		//!< フォントのインターフェイス
	LPDIRECT3DDEVICE9		m_pD3Device;	//!< DirectXのデバイス

};

#endif // !FONT_H