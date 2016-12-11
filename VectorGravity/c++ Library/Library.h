/**
 * @file	Library.h
 * @breif	ライブラリ全体を統括するクラスヘッダ
 * @author	shibata
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#define DIRECTINPUT_VERSION 0x0800

#include <d3dx9.h>
#include <dinput.h>

#pragma comment ( lib, "dsound.lib" )
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "Xinput.lib")

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

enum KeyKind;
class WindowCreate;
class GraphicsDevice;
class TextureManager;
class Font;
class InputDevice;
class InputKey;
class InputContlloer;
class Sound;
class Vertex;

class Library
{
public:

	/**
	 * ライブラリクラスの情報取得
	 * @return library
	 */
	static Library& Instance()
	{
		static Library library;

		return library;
	}

	/**
	 * デストラクタ
	 */
	~Library();
 
	/**
	 * DirectXの初期化関数
	 * @retrun なし
	 */
	void Initlibrary(HINSTANCE hinstance_, LRESULT CALLBACK WindowProc_(HWND, UINT, WPARAM, LPARAM), TCHAR* titlename_, int clientwidth_, int clientheiht_, bool isfullscreen_);

	/**
	 * ウィンドウ生成関数
	 * @param [in] hinstance_		インスタンスハンドル
	 * @param [in] WindowProc_		ウィンドウプロシージャ
	 * @param [in] titlename_		ウィンドウネーム
	 * @param [in] clientwidth_		クライアントサイズの幅
	 * @param [in] clientheiht_		クライアントサイズの高さ
	 * @param [in] isfullscreen_	フルスクリーンにするかどうか
	 */
	void Create(HINSTANCE hinstance_, LRESULT CALLBACK WindowProc_(HWND, UINT, WPARAM, LPARAM), TCHAR* titlename_, int clientwidth_, int clientheiht_, bool isfullscreen_);

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

	/**
	 * 画像の読み込み
	 * @param  [in]	filepath_	画像ファイルのパス名
	 */
	void LoadTexture(int index_, const char* filepath_);

	/**
	 * 詳細な画像の読み込み
	 * @param [in]	filepath_	画像ファイルのパス名
	 * @param [in]	alpha_		画像の透過値			デフォルトは255
	 * @param [in]	red_		画像のR値				デフォルトは0
	 * @param [in]	green_		画像のG値				デフォルトは0
	 * @param [in]	blue_		画像のB値				デフォルトは0
	 * @param [in]	texsize_	2の累乗かどうか		デフォルトはtrue
	 */
	void LoadTextureEX(int index_, const char* filepath_, int alpha_ = 255, int red_ = 0, int green_ = 0, int blue_ = 0, bool texsize_ = true);

	/**
	* テクスチャサイズを指定する関数
	* @param [in] width_	テクスチャの幅
	* @param [in] height_	テクスチャの高さ
	* @param [in] maxtu_	テクスチャの最大x座標	デフォルト値は1.0f
	* @param [in] maxtv_	テクスチャの最大y座標	デフォルト値は1.0f
	* @param [in] mintu_	テクスチャの最小x座標	デフォルト値は0.0f
	* @param [in] mintv_	テクスチャの最小y座標	デフォルト値は0.0f
	*/
	void SetTextureSize(float width_, float height_, float maxtu_ = 1.0f, float maxtv_ = 1.0f, float mintu_ = 0.0f, float mintv_ = 0.0f);

	/**
	* 左上から描画する関数
	* @param [in] posx_		左上座標のx軸の値
	* @param [in] posy_		左上座標のy軸の値
	*/
	void DrawLeftTop(float posx_, float posy_, int index_);

	/**
	* 中心から描画する関数
	* @param [in] posx_		中心座標のx軸の値
	* @param [in] posy_		中心座標のy軸の値
	*/
	void DrawCenter(float posx_, float posy_, int index_);

	/**
	 * フォントの設定をする
	 * @param [in] heiht_ 文字の高さを決める
	 * @param [in] widht_ 文字の幅を決める
	 */
	void SetFontState(INT heiht_, UINT widht_);

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

	/**
	 * DirectInputの情報更新関数
	 */
	void GetInputState();

	/**
	 * キーボードの状態確認関数
	 * @param [in] dik_ どのDIKかを指定する
	 * @param [in] set_ DIKに対応したキーの種類
	 */
	void CheckKey(int dik_, KeyKind set_);

	/**
	* サウンドのインターフェイスの生成関数
	* @param	[in]	hWnd_	ウィンドウハンドル
	*/
	void InitSound(HWND hWnd_);
 
	/**
	* サウンドファイルの読み込み
	* @param	[in]	filepath_	音楽ファイルのパス
	*/
	void LoadSoundFile(TCHAR* filepath_);

	/**
	 * 再生状態を決定する関数
	 */
	//void SoundState();

private:

	/**
	* コンストラクタ
	* Singletonを使用しているためprivateにコンストラクタがある
	*/
	Library();

	WindowCreate*		m_pWindowCreate;	//!< ウィンドウ生成クラス
	GraphicsDevice*		m_pGraphicsDevice;	//!< DirectXのインターフェイスとデバイスを生成するクラス
	TextureManager*		m_pTextureManager;	//!< 画像を読み込むクラス
	Vertex*				m_pVertex;			//!< 
	Font*				m_pFont;			//!< 文字表示のクラス
	InputDevice*		m_pInputDevice;		//!< DirectInputのインターフェイスとデバイスを生成するクラス
	InputKey*			m_pInputKey;		//!< キーボード操作をするときに使うクラス
	InputContlloer*		m_pInputContlloer;	//!< Xboxコントローラー操作をするときに使うクラス
	Sound*				m_pSound;			//!< サウンドのインターフェイスの生成と音楽を再生するクラス

};

#endif // !LIBRARY_H