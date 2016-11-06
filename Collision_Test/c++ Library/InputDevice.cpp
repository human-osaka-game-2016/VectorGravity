#include "InputDevice.h"

HRESULT InputDevice::InitInput()
{
	if (FAILED(DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&m_pDinput, NULL)))
	{
		MessageBox(0, "DirectInput�I�u�W�F�N�g�����Ɏ��s���܂����B", NULL, MB_OK);
		return E_FAIL;
	}
	return S_OK;
}

HRESULT InputDevice::InitInputKey(HWND _hWnd)
{
	m_hWnd = _hWnd;

	if (FAILED(m_pDinput->CreateDevice(GUID_SysKeyboard,
		&m_pKeyDevice, NULL)))
	{
		MessageBox(0, "DirectInput�L�[�{�[�h�������Ɏ��s���܂����B", NULL, MB_OK);
		return E_FAIL;
	}

	//	�f�[�^�t�H�[�}�b�g
	if (FAILED(m_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//	�������x��
	if (FAILED(m_pKeyDevice->SetCooperativeLevel(
		m_hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return E_FAIL;
	}

	// �A�N�Z�X����
	m_pKeyDevice->Acquire();
	return S_OK;
}


