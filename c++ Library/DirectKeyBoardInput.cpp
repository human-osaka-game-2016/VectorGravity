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
	if ((m_diks[_dik] & 0x80))			// �擪�r�b�g�������Ă��邩�`�F�b�N���Ă���
	{
		if (m_PreKey[_set] == 0)
		{
			m_Key[_set] = PUSH;			// ��u����������
		}
		else
		{
			m_Key[_set] = ON;			// ���������Ă���
		}
		m_PreKey[_set] = 1;
	}
	else
	{
		if (m_PreKey[_set] == 0)
		{
			m_Key[_set] = OFF;			// ���������Ă���
		}
		else
		{
			m_Key[_set] = RELEASE;		// ��u����������
		}
		m_PreKey[_set] = 0;
	}

}

void InputKeyBorad::Release()
{
//	m_pKeyDevice->Release();
}