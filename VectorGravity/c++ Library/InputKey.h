/**
 * @file	InputKey.h
 * @breif	キークラスヘッダ
 * @author	shibata
 */

#ifndef INPUTKEY_H
#define INPUTKEY_H

#include "InputDevice.h"

/// キーの種類
enum  KeyKind
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	LCONTROL,
	SHIFT,
	SPACE,
	ENTER,
	KEYMAX,		
};

class InputKey
{
public:

	BYTE		m_diks[256];	//!< DirectInoputKeyを格納する変数
	ButtonState m_key[KEYMAX];	//!< 各キーを格納する変数

	static InputKey& Instance()
	{
		static InputKey inputKey;

		return inputKey;
	}

	/**
	 * デストラクタ
	 */
	~InputKey();

	/**
	 * キーボード状態取得関数
	 */
	void GetKeyBoradState();

	/**
	 * キーボードの状態確認関数
	 * @param [in] dik_ どのDIKかを指定する
	 * @param [in] set_ DIKに対応したキーの種類
	 */
	void CheckKey(int dik_, KeyKind set_);

private:

	/**
	* コンストラクタ
	*/
	InputKey();

	LPDIRECTINPUTDEVICE8	m_pKeyDevice;		//!< キーボード用デバイス
	int						m_preKey[KEYMAX];	//!< キーの状態を格納する変数

};

#endif // !INPUTKEY_H