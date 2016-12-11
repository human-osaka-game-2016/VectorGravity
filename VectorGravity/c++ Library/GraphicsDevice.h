/**
 * @file	GraphicsDevice.h
 * @breif	DirectXのインターフェイスの生成とグラフィックデバイスの生成クラスヘッダ
 * @author	shibata
 */

#ifndef GRAPHICSDEVICE_H
#define GRAPHICSDEVICE_H

#include <d3dx9.h>

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

class GraphicsDevice
{
public:

	/**
	 * グラフィックデバイスの情報取得
	 * @return graphicsDevice デバイス情報
	 */
	static GraphicsDevice& Instance()	
	{
		static GraphicsDevice graphicsDevice;
		
		return graphicsDevice;
	}

	/**
	 * デストラクタ
	 */
	~GraphicsDevice();

	/**
	 * DirectXのインターフェイスとデバイスの生成関数
	 * @param	[in] hWnd_			ウィンドウハンドル
	 * @param	[in] isfullscrenn_	フルスクリーンにするかしないか
	 * @retval	true				初期化の成功
	 * @retval	false				初期化の失敗
	 */
	bool InitDirect(HWND hWnd_, int width_, int heiht_, bool isfullscreen_);

	/**
	 * テクスチャの初期化
	 */
	void InitDraw();

	/**
	 * 柔軟な頂点フォーマットを設定する関数
	 * @param [in] fvf_ 頂点フォーマットの設定	デフォルトはD3DFVF_CUSTOMVERTEX
	 */
	void SetFVF(DWORD fvf_ = D3DFVF_CUSTOMVERTEX);

	/**
	 * 描画を始める関数
	 */
	void DrawStart();

	/**
	 * 描画を終了する関数
	 */
	void DrawEnd();
	
	/*
	 * デバイス受け取る関数
	 * 他のところでデバイスを使いたいときに使用する
	 * @return m_pD3Device 生成したデバイスを返す
	 */
	LPDIRECT3DDEVICE9 GraphicsDevice::GetDevice()
	{
		return m_pD3Device;
	}

private:

	/**
	 * コンストラクタ
	 * Singletonを使用しているためprivateにコンストラクタがある
	 */
	GraphicsDevice(){}

	LPDIRECT3D9				m_pDirect3D;	//!< DirectXのオブジェクト
	LPDIRECT3DDEVICE9		m_pD3Device;	//!< DirectXのデバイス
	D3DDISPLAYMODE			m_d3ddm;		//!< ディスプレイモード
	D3DPRESENT_PARAMETERS	m_d3dpp;		//!< 最終的なウィンドウパラメーター
	D3DPRESENT_PARAMETERS	m_d3dppFull;	//!< フルスクリーンの場合のウィンドウパラメーター
	D3DPRESENT_PARAMETERS	m_d3dppWindow;	//!< ウィンドウの場合のウィンドウパラメーター
};

#endif // !GRAPHICSDEVICE_H