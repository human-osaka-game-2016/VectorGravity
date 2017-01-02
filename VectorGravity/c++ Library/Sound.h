/**
* @file	Sound.h
* @breif	サウンドクラスヘッダ
* @author	shibata
*/

#ifndef SUONDMUSIC_H
#define SUONDMUSIC_H

#include "SoundDevice.h"

class Sound
{
public:

	enum SoundMode
	{
		PLAY,
		LOOP,
		STOP,
		RESET,
		RESET_STOP,
		RESET_PLAY
	};

	/**
	* コンストラクタ
	*/
	Sound();

	/**
	* デストラクタ
	*/
	~Sound();

	/**
	* サウンドファイルの読み込み
	* @param	[in]	filepath_	音楽ファイルのパス
	* @retval			S_OK		読み込み成功
	* @retval			E_FAIL		読み込み失敗
	*/
	HRESULT LoadSoundFile(TCHAR* filepath_);

	/**
	* @todo 仮置き
	* 再生状態を決める関数
	*/
	void SoundState(SoundMode soundstate_);

private:

	/**
	* waveファイルを開く関数
	* @param	[in]	filepath_		音楽ファイルのパス
	* @param	[out]	waveformat_		waveフォーマット
	* @param	[out]	ppdata_			waveデータサイズ
	* @param	[out]	datasize_		データサイズ
	* @retval			true			waveファイルの読み込み成功
	* @retval			false			waveファイルの読み込み失敗
	*/
	bool OpenWave(TCHAR* filepath_, WAVEFORMATEX* waveformat_, char** ppdata_, DWORD* datasize_);

	IDirectSound8*			m_pDsound8;			//!< サウンドインターフェイス
	IDirectSoundBuffer8*	m_pDsoundBuffer;	//!< サウンドバッファ
};

#endif // !SUONDMUSIC_H