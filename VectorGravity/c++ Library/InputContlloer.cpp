/**
 * @file	InputContlloer.cpp
 * @breif	コントローラークラスの実装内部
 * @author	shibata
 */

#include "InputContlloer.h"


InputContlloer::InputContlloer() : 
m_pContlloerDevice(InputDevice::Instance().GetContlloerDevice()),
m_kStickDeadZone(STICK_DEADZONE),
m_ktriggerDeadZone(TRIGGER_DEADZONE)
{

}

InputContlloer::~InputContlloer()
{

}

void InputContlloer::GetContlloerState()
{

}