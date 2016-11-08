#include "InputDevice.h"

HRESULT InputDevice::InitInput()
{
	if (FAILED(DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&m_pDinput, NULL)))
	{
		MessageBox(0, "DirectInputオブジェクト生成に失敗しました。", NULL, MB_OK);
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
		MessageBox(0, "DirectInputキーボード初期化に失敗しました。", NULL, MB_OK);
		return E_FAIL;
	}

	//	データフォーマット
	if (FAILED(m_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//	協調レベル
	if (FAILED(m_pKeyDevice->SetCooperativeLevel(
		m_hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return E_FAIL;
	}

	// アクセス許可
	m_pKeyDevice->Acquire();
	return S_OK;
}


