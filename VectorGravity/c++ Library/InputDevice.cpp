/**
 * @file	InputDevice.cpp
 * @breif	入力装置のインターフェイスとデバイスの生成クラスの実装内部
 * @author	shibata
 */

#include "InputDevice.h"

InputDevice::~InputDevice()
{
	if (m_pKeyDevice != NULL)
	{
		m_pKeyDevice->Release();
		m_pKeyDevice = NULL;
	}

	if (m_pContlloerDevice != NULL)
	{
		m_pContlloerDevice->Release();
		m_pContlloerDevice = NULL;
	}

	if (m_pDinput != NULL)
	{
		m_pDinput->Release();
		m_pDinput = NULL;
	}
}

HRESULT InputDevice::InitInput()
{
	if (FAILED(DirectInput8Create(GetModuleHandle(NULL), 
		DIRECTINPUT_VERSION, IID_IDirectInput8, 
		(VOID**)&m_pDinput, NULL)))
	{
		MessageBox(0, "DirectInputオブジェクト生成に失敗しました。", NULL, MB_OK);
		return E_FAIL;
	}
	return S_OK;
}

HRESULT InputDevice::InitInputKey(HWND hWnd_)
{
	m_hWnd = hWnd_;

	if (FAILED(m_pDinput->CreateDevice(GUID_SysKeyboard,
		&m_pKeyDevice, NULL)))
	{
		MessageBox(0, "DirectInputデバイスの生成に失敗しました。", NULL, MB_OK);
		return E_FAIL;
	}

	//	データフォーマット
	if (FAILED(m_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		MessageBox(0, "データフォーマットの設定に失敗しました。", NULL, MB_OK);

		return E_FAIL;
	}

	//	協調レベル
	if (FAILED(m_pKeyDevice->SetCooperativeLevel(
		m_hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
	{
		MessageBox(0, "協調levelの設定に失敗しました。", NULL, MB_OK);

		return E_FAIL;
	}

	// アクセス許可
	m_pKeyDevice->Acquire();
	return S_OK;
}

HRESULT InputDevice::InitInputMouse(HWND hWnd_)
{
	m_hWnd = hWnd_;

	if (FAILED(m_pDinput->CreateDevice(GUID_SysMouse,
		&m_pMouseDevice, NULL)))
	{
		MessageBox(0, "DirectInputデバイスの生成に失敗しました。", NULL, MB_OK);
		return E_FAIL;
	}

	//	データフォーマット
	if (FAILED(m_pMouseDevice->SetDataFormat(&c_dfDIMouse)))
	{
		MessageBox(0, "データフォーマットの設定に失敗しました。", NULL, MB_OK);

		return E_FAIL;
	}

	//	協調レベル
	if (FAILED(m_pMouseDevice->SetCooperativeLevel(
		m_hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
	{
		MessageBox(0, "協調levelの設定に失敗しました。", NULL, MB_OK);

		return E_FAIL;
	}

	/// @todo 軸モードの設定を後にする

	// アクセス許可
	m_pMouseDevice->Acquire();
	return S_OK;
}

/// @todo このコールバック関数もstaticにしてこの処理をしたら通ったのでのちに調べる必要あり
BOOL CALLBACK InputDevice::EnumJoysSticksCallBack(const DIDEVICEINSTANCE* pdeviceinstance_, LPVOID pcontext_)
{
	InputDevice* pDevice = (InputDevice*)pcontext_;

	if (pDevice->m_pDinput->CreateDevice(pdeviceinstance_->guidInstance,
		&pDevice->m_pContlloerDevice, NULL))
	{
		return DIENUM_CONTINUE;
	}

	return DIENUM_STOP;
}

HRESULT InputDevice::InitInputContlloer(HWND hWnd_)
{
	m_hWnd = hWnd_;

	if (m_pDinput->EnumDevices(DI8DEVCLASS_GAMECTRL, EnumJoysSticksCallBack, (void*)this, DIEDFL_ATTACHEDONLY))		/// @todo ネットでこう書いてたら通ると書いていたので。調べる必要あり
	{
		MessageBox(0, "デバイスが生成できませんでした。", NULL, MB_OK);

		return E_FAIL;
	}

	if (FAILED(m_pContlloerDevice->SetDataFormat(&c_dfDIJoystick2)))
	{
		MessageBox(0, "データフォーマットの設定に失敗しました。", NULL, MB_OK);

		return E_FAIL;
	}

	if (FAILED(m_pContlloerDevice->SetCooperativeLevel(m_hWnd, DISCL_EXCLUSIVE | DISCL_FOREGROUND)))
	{
		MessageBox(0, "協調levelの設定に失敗しました。", NULL, MB_OK);

		return E_FAIL;
	}

	DIDEVCAPS diDevcaps;

	/// @todo 軸モードの設定を後にする

	if (FAILED(m_pContlloerDevice->GetCapabilities(&diDevcaps)))
	{
		return E_FAIL;
	}

	m_pContlloerDevice->Acquire();

	return S_OK;
}