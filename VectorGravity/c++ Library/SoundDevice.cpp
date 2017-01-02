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
	if (FAILED(DirectSoundCreate8(NULL, &m_pDsound8, NULL)))			// �I�u�W�F�N�g�̐����Ə�����
	{
		MessageBox(NULL, "�I�u�W�F�N�g�������ł��܂���ł����B", NULL, MB_OK);
		return E_FAIL;
	}
	if (FAILED(m_pDsound8->SetCooperativeLevel(hWnd_, DSSCL_PRIORITY)))		// �������x���̐ݒ�
	{
		MessageBox(NULL, "�������x�����ݒ�ł��܂���ł����B", NULL, MB_OK);
		return E_FAIL;
	}

	return S_OK;
}