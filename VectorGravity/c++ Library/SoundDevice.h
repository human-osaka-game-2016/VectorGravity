/**
* @file	SoundDevice.h
* @breif	サウンドのインターフェイスとデバイスの生成クラスヘッダ
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
	* サウンドのインターフェイスの生成関数
	* @param	[in]	hWnd_	ウィンドウハンドル
	* @retval			S_OK	生成成功
	* @retval			E_FAIL	生成失敗
	*/
	HRESULT InitSound(HWND hWnd_);

	IDirectSound8* GetSoundDivice()
	{
		return m_pDsound8;
	}

private:
	SoundDevice();

	IDirectSound8*			m_pDsound8;			//!< サウンドインターフェイス

};

#endif // !SOUNDDEVICE_H