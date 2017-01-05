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

struct ControllerState
{
	XINPUT_STATE xinputState;
	XINPUT_VIBRATION xinputVibration;
};

/// コントローラーのボタンの種類
enum ButtonKind
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
	LEFT_SHOULDER,
	LEFT_TRIGGER,
	RIGHT_TRIGGER,
	LEFT_THUMBSTICK,
	RIGHT_THUMBSTICK,
	BUTTON_MAX
};

enum ContlloerNumber
{
	CONTLLOER_1,
	CONTLLOER_2,
	CONTLLOER_3,
	CONTLLOER_4,
	CONTLLOER_MAX
};

enum PadState
{
	PAD_PUSH,
	PAD_RELEASE,
	PAD_ON,
	PAD_OFF

};

class InputContlloer
{
public:

	PadState m_padButton[CONTLLOER_MAX][BUTTON_MAX];

	static InputContlloer& Instance()
	{
		static InputContlloer inputContlloer;

		return inputContlloer;
	}

	/**
	 * デストラクタ
	 */
	~InputContlloer();

	/**
	 * コントローラーの状態取得関数
	 */
	void GetContlloerState(ContlloerNumber number_ = CONTLLOER_1);

	void CheckButton(int xinput_, ButtonKind button_, ContlloerNumber number_ = CONTLLOER_1);

	void CheckTriger(ButtonKind trigger_, ContlloerNumber number_ = CONTLLOER_1);

	void CheckStick(ButtonKind stick_, ContlloerNumber number_ = CONTLLOER_1);

private:
	/**
	* コンストラクタ
	*/
	InputContlloer();



	ControllerState			m_controllerState[CONTLLOER_MAX];
	int						m_prePad[CONTLLOER_MAX][BUTTON_MAX];
	const float				m_kStickDeadZone;		//!< スティックを動かしても反応しない範囲を格納する変数
	const float				m_ktriggerDeadZone;		//!< トリガーを押しても反応しない範囲を格納する変数
};

#endif // !INPUTCONTLLOER_H