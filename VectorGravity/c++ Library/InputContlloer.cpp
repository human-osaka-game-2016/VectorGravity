/**
 * @file	InputContlloer.cpp
 * @breif	コントローラークラスの実装内部
 * @author	shibata
 */

#include "InputContlloer.h"


InputContlloer::InputContlloer() :
m_kStickDeadZone(STICK_DEADZONE),
m_ktriggerDeadZone(TRIGGER_DEADZONE)
{
	for (int i = 0; i < CONTLLOER_MAX; i++)
	{
		for (int j = 0; j < BUTTON_MAX; j++)
		{
			m_prePad[i][j] = { PAD_OFF };
			m_padButton[i][j] = { PAD_OFF };
		}
	}
}

InputContlloer::~InputContlloer()
{

}

void InputContlloer::GetContlloerState(ContlloerNumber number_)
{
	XInputGetState(number_, &m_controllerState[number_].xinputState);
}

void InputContlloer::CheckButton(int xinput_, ButtonKind button_, ContlloerNumber number_)
{
	if (m_controllerState[number_].xinputState.Gamepad.wButtons & xinput_)
	{
		if (m_prePad[number_][button_] == PAD_OFF)
		{
			m_padButton[number_][button_] = PAD_ON;
		}
		else
		{
			m_padButton[number_][button_] = PAD_PUSH;
		}
		m_prePad[number_][button_] = PAD_ON;
	}
	else
	{
		if (m_prePad[number_][button_] == PAD_ON)
		{
			m_padButton[number_][button_] = PAD_RELEASE;
		}
		else
		{
			m_padButton[number_][button_] = PAD_OFF;
		}
		m_prePad[number_][button_] = PAD_OFF;
	}
}

void InputContlloer::CheckTriger(ButtonKind trigger_, ContlloerNumber number_)
{
	switch (trigger_)
	{
	case LEFT_TRIGGER:
		if (m_ktriggerDeadZone < m_controllerState[number_].xinputState.Gamepad.bLeftTrigger)
		{
			m_padButton[number_][trigger_] = PAD_PUSH;
		}
		else
		{
			m_padButton[number_][trigger_] = PAD_RELEASE;
		}
		break;

	case RIGHT_TRIGGER:
		if (m_ktriggerDeadZone < m_controllerState[number_].xinputState.Gamepad.bRightTrigger)
		{
			m_padButton[number_][trigger_] = PAD_PUSH;
		}
		else
		{
			m_padButton[number_][trigger_] = PAD_OFF;
		}
		break;
	}
}

void InputContlloer::CheckStick(ButtonKind stick_, StickDirection direction_, ContlloerNumber number_)
{
	switch (stick_)
	{
	case LEFT_THUMBSTICK:

		switch (direction_)
		{
		case STICK_LEFT:
			if (m_controllerState[number_].xinputState.Gamepad.sThumbLX < -m_kStickDeadZone)
			{
				m_padStick[number_][direction_][stick_] = PAD_ON;
			}
			else
			{
				m_padStick[number_][direction_][stick_] = PAD_OFF;
			}
			break;

		case STICK_RIGHT:
			if (m_controllerState[number_].xinputState.Gamepad.sThumbLX > m_kStickDeadZone)
			{
				m_padStick[number_][direction_][stick_] = PAD_ON;
			}
			else
			{
				m_padStick[number_][direction_][stick_] = PAD_OFF;
			}
			break;

		case STICK_UP:
			if (m_controllerState[number_].xinputState.Gamepad.sThumbLY > m_kStickDeadZone)
			{
				m_padStick[number_][direction_][stick_] = PAD_ON;
			}
			else
			{
				m_padStick[number_][direction_][stick_] = PAD_OFF;
			}
			break;

		case STICK_DOWN:
			if (m_controllerState[number_].xinputState.Gamepad.sThumbLY < -m_kStickDeadZone)
			{
				m_padStick[number_][direction_][stick_] = PAD_ON;
			}
			else
			{
				m_padStick[number_][direction_][stick_] = PAD_OFF;
			}
			break;
		}
		break;
	}
}
