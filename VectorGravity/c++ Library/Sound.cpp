/**
* @file	Sound.cpp
* @breif	サウンドクラス実装内部
* @author	shibata
*/

#include "Sound.h"
#include <tchar.h>

Sound::Sound() :
m_pDsound8(SoundDevice::Instance().GetSoundDivice()),
m_pDsoundBuffer(NULL)
{

}

Sound::~Sound()
{
	m_pDsoundBuffer->Release();
}

bool Sound::OpenWave(TCHAR* filepath_, WAVEFORMATEX* waveformat_, char** ppdata_, DWORD* datasize_)
{
	// 音声ファイルの名前
	if (filepath_ == 0)
	{
		return false;
	}

	HMMIO hmmio = NULL;
	MMIOINFO mmioinfo;			//ファイルをオープンするときはゼロで初期化して渡す必要がある

	// Waveファイルオープン
	memset(&mmioinfo, NULL, sizeof(MMIOINFO));
	hmmio = mmioOpen(filepath_, &mmioinfo, MMIO_READ);
	if (!hmmio)
	{
		MessageBox(NULL, "ファイルのオープンに失敗しました。", NULL, MB_ICONWARNING);
		return false; // ファイルオープン失敗
	}

	// RIFFチャンク検索
	MMRESULT mmres;
	MMCKINFO riffchunk;
	riffchunk.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	mmres = mmioDescend(hmmio, &riffchunk, NULL, MMIO_FINDRIFF);
	if (mmres != MMSYSERR_NOERROR)
	{
		mmioClose(hmmio, 0);
		return false;
	}

	// フォーマットチャンク検索
	MMCKINFO formatchunk;
	formatchunk.ckid = mmioFOURCC('f', 'm', 't', ' ');
	mmres = mmioDescend(hmmio, &formatchunk, &riffchunk, MMIO_FINDCHUNK);
	if (mmres != MMSYSERR_NOERROR)
	{
		mmioClose(hmmio, 0);
		return false;
	}
	DWORD fmsize = formatchunk.cksize;
	DWORD size = mmioRead(hmmio, (HPSTR)waveformat_, fmsize);
	if (size != fmsize)
	{
		mmioClose(hmmio, 0);
		return false;
	}

	mmioAscend(hmmio, &formatchunk, 0);

	// データチャンク検索
	MMCKINFO datachunk;
	datachunk.ckid = mmioFOURCC('d', 'a', 't', 'a');
	mmres = mmioDescend(hmmio, &datachunk, &riffchunk, MMIO_FINDCHUNK);
	if (mmres != MMSYSERR_NOERROR)
	{
		mmioClose(hmmio, 0);
		return false;
	}
	*ppdata_ = new char[datachunk.cksize];
	size = mmioRead(hmmio, (HPSTR)*ppdata_, datachunk.cksize);
	if (size != datachunk.cksize)
	{
		delete[] * ppdata_;
		return false;
	}
	*datasize_ = size;

	// ハンドルクローズ
	mmioClose(hmmio, 0);

	return true;
}

HRESULT Sound::LoadSoundFile(TCHAR* filepath_)
{
	WAVEFORMATEX waveformat;
	char *pwavedata = 0;
	DWORD wavesize = 0;
	if (!OpenWave(_T(filepath_), &waveformat, &pwavedata, &wavesize))
	{
		return E_FAIL;
	}

	DSBUFFERDESC			DSBufferDesc;				// 新しいバッファオブジェクトの特性を書いておく構造体
	DSBufferDesc.dwSize = sizeof(DSBUFFERDESC);
	DSBufferDesc.dwFlags = 0;
	DSBufferDesc.dwBufferBytes = wavesize;
	DSBufferDesc.dwReserved = 0;						//0でなければならない
	DSBufferDesc.lpwfxFormat = &waveformat;				//WAVEFORMATEXのアドレス
	DSBufferDesc.guid3DAlgorithm = GUID_NULL;			//デフォルトのアルゴリズムを使う

	IDirectSoundBuffer*		ptempBuf = NULL;			// プライマリバッファの場合は使う必要がある
	m_pDsound8->CreateSoundBuffer(&DSBufferDesc, &ptempBuf, NULL);
	ptempBuf->QueryInterface(IID_IDirectSoundBuffer8, (void**)&m_pDsoundBuffer);
	ptempBuf->Release();

	// セカンダリバッファにWaveデータ書き込み
	LPVOID lpvwrite = NULL;
	DWORD dwlength = NULL;
	if (DS_OK == m_pDsoundBuffer->Lock(0, 0, &lpvwrite, &dwlength, NULL, NULL, DSBLOCK_ENTIREBUFFER))
	{
		memcpy(lpvwrite, pwavedata, dwlength);
		m_pDsoundBuffer->Unlock(lpvwrite, dwlength, NULL, 0);
	}

	delete[] pwavedata;

	return S_OK;

}

void Sound::SoundState(SoundMode soundstate_)
{
	switch (soundstate_)
	{
	case PLAY:
		m_pDsoundBuffer->Play(0, 0, 0);
		break;

	case LOOP:
		m_pDsoundBuffer->Play(0, 0, DSBPLAY_LOOPING);
		break;

	case STOP:
		m_pDsoundBuffer->Stop();
		break;

	case RESET:
		m_pDsoundBuffer->SetCurrentPosition(0);
		break;

	case RESET_STOP:
		m_pDsoundBuffer->Stop();
		m_pDsoundBuffer->SetCurrentPosition(0);
		break;
	case RESET_PLAY:
		m_pDsoundBuffer->SetCurrentPosition(0);
		m_pDsoundBuffer->Play(0, 0, 0);
		break;
	}
}