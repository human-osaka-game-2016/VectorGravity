#ifndef KEYINPUT
#define KEYINPUT

#include "InputDevice\InputDevice.h"


enum  KEYKIND
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
	SHIFT,
	SPACE,
	ENTER,
	LCONTROL,
	KEYMAX,		///<格納してるキーの最大値
};

/// キーの状態
enum KEYSTATE
{
	PUSH,		///<キーを押した瞬間
	RELEASE,	///<キーを離した瞬間
	ON,			///<押し続けているとき
	OFF,			///<離し続けているとき
};

class InputKeyBorad
{
private:

	LPDIRECTINPUTDEVICE8	m_pKeyDevice;
	int		 m_PreKey[KEYMAX];

public:

	BYTE     m_diks[256];
	KEYSTATE m_Key[KEYMAX];

	InputKeyBorad();
	~InputKeyBorad();

	static InputKeyBorad& GetInstance()
	{
		static InputKeyBorad inputkeyborad;

			return inputkeyborad;
	}

	void GetKeyBoradState();
	void KeyCheck(int _dik, KEYKIND _set);

};


#endif