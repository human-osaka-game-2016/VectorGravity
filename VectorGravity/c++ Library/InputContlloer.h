/**
 * @file	InputContlloer.h
 * @breif	コントローラークラスヘッダ
 * @author	shibata
 */

#ifndef INPUTCONTLLOER_H
#define INPUTCONTLLOER_H

#include <Windows.h>
#include <XInput.h>
#include "InputDevice.h"

#define STICK_DEADZONE		0.20f * float(0X7777)	//!< スティックを動かしても反応しない範囲
#define TRIGGER_DEADZONE	30						//!< トリガーを押しても反応しない範囲
#define CONTLLOER_MAX		4						//!< コントローラーの最大接続数

/// コントローラーのボタンの種類
enum ContlloerKind
{
	START_BUTTON,
	BACK_BUTTON,
	A_BUTTON,
	B_BUTTON,
	X_BUTTON,
	Y_BUTTON,
	DPAD_UP,
	DPAD_DOWN,
	DPAD_LEFT,
	DPAD_RIGHT,
	RIGHT_SHOULDER,
	LEFT_SHOULDER
};

class InputContlloer
{
public:

	/**
	 * コンストラクタ
	 */
	InputContlloer();

	/**
	 * デストラクタ
	 */
	~InputContlloer();

	/**
	 * コントローラーの状態取得関数
	 */
	void GetContlloerState();

private:

	struct ControllerState
	{
		XINPUT_STATE xinputState;
		XINPUT_VIBRATION xinputVibration;
		bool connected;
	};

	ControllerState			m_controllerState;
	LPDIRECTINPUTDEVICE8	m_pContlloerDevice;		//!< DirectInputのコントローラー用のデバイス
	const float				m_kStickDeadZone;		//!< スティックを動かしても反応しない範囲を格納する変数
	const float				m_ktriggerDeadZone;		//!< トリガーを押しても反応しない範囲を格納する変数
};

#endif // !INPUTCONTLLOER_H