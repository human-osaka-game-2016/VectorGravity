/**
 * @file	InputDevice.h
 * @breif	入力装置のインターフェイスとデバイスの生成クラスヘッダ
 * @author	shibata
 */

#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>

/// @todo ここにこれを置くのは違うと思うので変更の可能性あり
/// ボタンの押された状態
enum ButtonState
{
	PUSH,
	RELEASE,
	ON,
	OFF
};

class InputDevice
{
public:

	/**
	 * Inputデバイスの情報取得
	 * @return inputDevice デバイス情報
	 */
	static InputDevice& Instance()
	{
		static InputDevice inputDevice;

		return inputDevice;
	}
 
	/*
	 * デストラクタ
	 */
	~InputDevice();

	/**
	 * Inputインターフェイスの生成関数
	 * @retval S_OK		生成成功
	 * @retval E_FAIL	生成失敗
	 */
	HRESULT InitInput();

	/**
	 * キーボードのデバイスの生成関数
	 * @param [in]	hWnd_	ウィンドウハンドル
	 * @retval		S_OK	生成成功
	 * @retval		E_FAIL	生成失敗
	 */
	HRESULT InitInputKey(HWND hWnd_);

	/// マウスのデバイスの生成関数
	/**	 
	 * @param [in]	hWnd_	ウィンドウハンドル
	 * @retval		S_OK	生成成功
	 * @retval		E_FAIL	生成失敗
	 */
	HRESULT InitInputMouse(HWND hWnd_);

	/**
	 * ジョイスティックデバイスの取得に必要なコールバック関数
	 */
	static BOOL CALLBACK EnumJoysSticksCallBack(const DIDEVICEINSTANCE* pdeviceinstance_, LPVOID pcontext_);

	/**
	 * コントローラーのデバイスの生成関数
	 * @param [in]	hWnd_	ウィンドウハンドル
	 * @retval		S_OK	生成成功
	 * @retval		E_FAIL	生成失敗
	 */
	HRESULT InitInputContlloer(HWND hWnd_);

	/**
	 * キーボード用デバイスの取得関数
	 * @return m_pKeyDevice	キーボード用デバイス
	 */
	LPDIRECTINPUTDEVICE8 InputDevice::GetKeyDevice()
	{
		return m_pKeyDevice;
	}

	/**
	 * マウス用デバイスの取得関数
	 * @return m_pMouseDevice マウス用デバイス
	 */
	LPDIRECTINPUTDEVICE8 InputDevice::GetMouseDevice()
	{
		return m_pMouseDevice;
	}

	/**
	 * コントローラー用デバイス取得関数
	 * @return m_pContlloerDevice コントローラー用デバイス
	 */
	LPDIRECTINPUTDEVICE8 InputDevice::GetContlloerDevice()
	{
		return m_pContlloerDevice;
	}

private:

	/**
	* コンストラクタ
	* Singletonを使用しているためprivateにコンストラクタがある
	*/
	InputDevice(){}

	HWND					m_hWnd;					//!< ウィンドウハンドル
	LPDIRECTINPUT8			m_pDinput;				//!< DirectInputのオブジェクト
	LPDIRECTINPUTDEVICE8	m_pKeyDevice;			//!< DirectInputのキーボード用デバイス
	LPDIRECTINPUTDEVICE8	m_pMouseDevice;			//!< DirectInputのマウス用デバイス
	LPDIRECTINPUTDEVICE8	m_pContlloerDevice;		//!< DirectInputのコントローラー用のデバイス

};

#endif // !INPUTDEVICE_H 