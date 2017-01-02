/**
* @file	SoundDevice.h
* @breif	�T�E���h�̃C���^�[�t�F�C�X�ƃf�o�C�X�̐����N���X�w�b�_
* @author	shibata
*/

#ifndef SOUNDDEVICE_H
#define SOUNDDEVICE_H

#include <dsound.h>

class SoundDevice
{
public:
	~SoundDevice();

	static SoundDevice& Instance()
	{
		static SoundDevice soundDevice;

		return soundDevice;
	}

	/**
	* �T�E���h�̃C���^�[�t�F�C�X�̐����֐�
	* @param	[in]	hWnd_	�E�B���h�E�n���h��
	* @retval			S_OK	��������
	* @retval			E_FAIL	�������s
	*/
	HRESULT InitSound(HWND hWnd_);

	IDirectSound8* GetSoundDivice()
	{
		return m_pDsound8;
	}

private:
	SoundDevice();

	IDirectSound8*			m_pDsound8;			//!< �T�E���h�C���^�[�t�F�C�X

};

#endif // !SOUNDDEVICE_H