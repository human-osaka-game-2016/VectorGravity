#include "SoundDevice.h"

SoundDevice::SoundDevice() :
m_pDsound8(NULL)
{

}

SoundDevice::~SoundDevice()
{
	if (m_pDsound8 != NULL)
	{
		m_pDsound8->Release();
	}
}

HRESULT SoundDevice::InitSound(HWND hWnd_)
{
	if (FAILED(DirectSoundCreate8(NULL, &m_pDsound8, NULL)))			// オブジェクトの生成と初期化
	{
		MessageBox(NULL, "オブジェクトが生成できませんでした。", NULL, MB_OK);
		return E_FAIL;
	}
	if (FAILED(m_pDsound8->SetCooperativeLevel(hWnd_, DSSCL_PRIORITY)))		// 協調レベルの設定
	{
		MessageBox(NULL, "協調レベルが設定できませんでした。", NULL, MB_OK);
		return E_FAIL;
	}

	return S_OK;
}