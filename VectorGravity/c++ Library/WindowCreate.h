/**
 * @file	WindowCreate.h
 * @breif	ウィンドウ生成のクラスヘッダ
 * @author	shibata
 */

#ifndef WINDOWCREATE_H
#define WINDOWCREATE_H

#include <Windows.h>

class WindowCreate
{
public:

	/**
	 * コンストラクタ
	 */
	WindowCreate();

	/**
	 * デストラクタ
	 */
	~WindowCreate();

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

	HWND GetHwnd()
	{
		return m_hWnd;
	}

private:

	HWND			m_hWnd;				//!< ウィンドウハンドル
	WNDCLASSEX		m_windowClass;		//!< ウィンドウ登録クラス
	int				m_clientWidth;		//!< クライアントサイズの幅
	int				m_clientHeiht;		//!< クライアントサイズの高さ

};

#endif // !WINDOWCREATE_H