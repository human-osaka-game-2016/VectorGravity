/**
 * @file GraiphcsDevice.h
 * @breif DirectXのオブジェクトやデバイスを生成している
*/

#ifndef GRAPHICSDEVICE
#define GRAPHICSDEVICE

#include <d3dx9.h>

class GraphicsDevice
{
private:

	/**
	* シングルトンパターンを使用しているのでコンストラクタはprivateに入れている
	*/
	GraphicsDevice(){}

	/**
	* シングルトンパターンのためのコピーコンストラクタ
	*/
	GraphicsDevice(const GraphicsDevice &other){}

	/**
	* よく分からん
	*/
	GraphicsDevice &operator = (const GraphicsDevice &other){}

	IDirect3D9*	m_pDirect3D;		//!< DirectXのオブジェクトのポインタ
	IDirect3DDevice9* m_pD3Device;	//!< DirectXのデバイスのポインタ
	D3DPRESENT_PARAMETERS m_d3dpp;	//!< バッファ設定に必要なものだったはず
	HWND m_hWnd;					//!< ウィンドハンドル

public:

	//!< シングルトンパターン
	static GraphicsDevice& getInstance()
	{
		static GraphicsDevice graphicsDevice;
		
		return graphicsDevice;
	}

	/// DirectXのオブジェクトとデバイスの初期化関数
	/**
	* @param [in]	_hWnd ウィンドハンドル
	* @retval true	初期化成功 
	* @retval false 初期化失敗 
	*/
	bool InitDirect(HWND _hWnd);

	/// テクスチャを張るための初期化
	/**
	* @attention InitDirectで呼んであいるので関数を呼ぶ必要はない
	*/
	void InitDraw();

	/// 頂点フォーマットを設定する関数
	/**
	* 実装cppでフォーマットを設定しなければならない
	*/
	void SetFVF(DWORD _fvf);

	/// 描画を始めるときの関数
	/**
	* 描画まとめているところで１回呼べばいい
	*/
	void DrawStart();

	/// 描画の終了するときの関数
	/**
	* 描画をまとめているところで1回呼べばいい
	*/
	void DrawEnd();

	/// デバイスをロストしたときの対処関数
	/**
	* デバイスがロストされたときに呼ばれる
	*/
	bool DeviceLost();

	/// デバイスをもう1回取得する関数
	/**
	* ロストしたときに呼ばれる
	*/
	void ResetDevice();
	
	/// 現在のデバイス取得関数
	/**
	* @return DirectXのデバイスのポインタ
	*/
	IDirect3DDevice9* GetDevice();

};

#endif