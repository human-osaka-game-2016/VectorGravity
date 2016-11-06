#include "DirectInput.h"


InputKeyBorad::InputKeyBorad() :
m_pKeyDevice(InputDevice::GetInstance().GetKeyDevice())
{
	for (int i = 0; i < KEYMAX; i++)
	{
		m_PreKey[KEYMAX] = { OFF };
	}
}

InputKeyBorad::~InputKeyBorad()
{

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
	if ((m_diks[_dik] & 0x80))			
	{
		if (m_PreKey[_set] == 0)
		{
			m_Key[_set] = PUSH;			
		}
		else
		{
			m_Key[_set] = ON;		
		}
		m_PreKey[_set] = 1;
	}
	else
	{
		if (m_PreKey[_set] == 0)
		{
			m_Key[_set] = OFF;		
		}
		else
		{
			m_Key[_set] = RELEASE;		
		}
		m_PreKey[_set] = 0;
	}

}