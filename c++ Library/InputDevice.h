#ifndef INPUTDEVICE
#define INPUTDEVICE

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>

class InputDevice
{
private:

	HWND					m_hWnd;					//!< ウィンドハンドル
	LPDIRECTINPUT8			m_pDinput;				//!< Inputのインターフェイス
	LPDIRECTINPUTDEVICE8	m_pKeyDevice;			//!< Inputのキーボード用デバイス
	LPDIRECTINPUTDEVICE8	m_pContlloerDevice;		//!< Inputのコントローラー用のデバイス

	/// コンストラクタ
	/**
	* シングルトンパターンを使用しているのでコンストラクタはprivateに入れている
	*/
	InputDevice(){}

	/// コピーコンストラクタ
	/**
	* シングルトンパターンのためのコピーコンストラクタ
	*/
	InputDevice(const InputDevice &other){}

	/// 基本無視の方向で
	InputDevice &operator = (const InputDevice &other){}

public:

	/// シングルトンパターン
	static InputDevice& GetInstance()
	{
		static InputDevice inputdevice;

		return inputdevice;
	}

	/// Inputのインターフェイスを生成
	/**
	* @attention WinMain関数で1回呼べばOK
	* @retval S_OK		生成が成功
	* @retval E_FAIL	生成が失敗
	*/
	HRESULT InitInput();

	/// 
	/**
	* 
	* @attention
	* @param [in] _hWnd
	* @retval S_OK
	* @retval E_FAIL
	*/
	HRESULT InitInputKey(HWND _hWnd);
	HRESULT InitInputContlloer(HWND _hWnd);

	LPDIRECTINPUTDEVICE8 GetKeyDevice(){ return m_pKeyDevice; };
	LPDIRECTINPUTDEVICE8 GetContlloerDevice(){ return m_pContlloerDevice; };

};

#endif