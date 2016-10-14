#ifndef INPUTDEVICE
#define INPUTDEVICE

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>

class InputDevice
{
private:

	HWND					m_hWnd;
	LPDIRECTINPUT8			m_pDinput;
	LPDIRECTINPUTDEVICE8	m_pKeyDevice;
	LPDIRECTINPUTDEVICE8	m_pContlloerDevice;

	InputDevice(){}
	InputDevice(const InputDevice &other){}
	InputDevice &operator = (const InputDevice &other){}

public:

	static InputDevice& GetInstance()
	{
		static InputDevice inputdevice;

		return inputdevice;
	}

	HRESULT InitInput();
	HRESULT InitInputKey(HWND _hWnd);
	HRESULT InitInputContlloer(HWND _hWnd);

	LPDIRECTINPUTDEVICE8 GetKeyDevice(){ return m_pKeyDevice; };
	LPDIRECTINPUTDEVICE8 GetContlloerDevice(){ return m_pContlloerDevice; };

};

#endif