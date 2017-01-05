/**
 * @file	InputKey.cpp
 * @breif	キークラスの実装内部
 * @author	shibata
 */

#include "InputKey.h"

InputKey::InputKey() :
m_pKeyDevice(InputDevice::Instance().GetKeyDevice())
{
	for(int i = 0; i < KEYMAX; i++)
	{
		m_preKey[i] = { 0 };
	}
}

InputKey::~InputKey()
{

}

void InputKey::GetKeyBoradState()
{
	HRESULT hr = m_pKeyDevice->Acquire();

	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		m_pKeyDevice->GetDeviceState(sizeof(m_diks), &m_diks);
	}
}

void InputKey::CheckKey(int _dik, KeyKind _set)
{
	if ((m_diks[_dik] & 0x80))			
	{
		if (m_preKey[_set] == 0)
		{
			m_key[_set] = PUSH;			
		}
		else
		{
			m_key[_set] = ON;			
		}
		m_preKey[_set] = 1;
	}
	else
	{
		if (m_preKey[_set] == 0)
		{
			m_key[_set] = OFF;			
		}
		else
		{
			m_key[_set] = RELEASE;		
		}
		m_preKey[_set] = 0;
	}

}