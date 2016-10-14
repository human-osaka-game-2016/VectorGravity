#include "DirectInput.h"

InputKeyBorad::InputKeyBorad() :
m_pKeyDevice(InputDevice::GetInstance().GetKeyDevice())
{
	m_PreKey[KEYMAX] = { 0 };
}

InputKeyBorad::~InputKeyBorad()
{
	Release();
}

void InputKeyBorad::GetKeyBoradState()
{
	HRESULT hr = m_pKeyDevice->Acquire();

	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		m_pKeyDevice->GetDeviceState(sizeof(m_diks), &m_diks);
	}
}

void InputKeyBorad::KeyCheck(int _dik, KEYKIND _set)
{
	if ((m_diks[_dik] & 0x80))			// 先頭ビットがたっているかチェックしている
	{
		if (m_PreKey[_set] == 0)
		{
			m_Key[_set] = PUSH;			// 一瞬だけ押した
		}
		else
		{
			m_Key[_set] = ON;			// 押し続けている
		}
		m_PreKey[_set] = 1;
	}
	else
	{
		if (m_PreKey[_set] == 0)
		{
			m_Key[_set] = OFF;			// 離し続けている
		}
		else
		{
			m_Key[_set] = RELEASE;		// 一瞬だけ離した
		}
		m_PreKey[_set] = 0;
	}

}

void InputKeyBorad::Release()
{
//	m_pKeyDevice->Release();
}