#ifndef INPUTDEVICE
#define INPUTDEVICE

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>

class InputDevice
{
private:

	HWND					m_hWnd;					//!< �E�B���h�n���h��
	LPDIRECTINPUT8			m_pDinput;				//!< Input�̃C���^�[�t�F�C�X
	LPDIRECTINPUTDEVICE8	m_pKeyDevice;			//!< Input�̃L�[�{�[�h�p�f�o�C�X
	LPDIRECTINPUTDEVICE8	m_pContlloerDevice;		//!< Input�̃R���g���[���[�p�̃f�o�C�X

	/// �R���X�g���N�^
	/**
	* �V���O���g���p�^�[�����g�p���Ă���̂ŃR���X�g���N�^��private�ɓ���Ă���
	*/
	InputDevice(){}

	/// �R�s�[�R���X�g���N�^
	/**
	* �V���O���g���p�^�[���̂��߂̃R�s�[�R���X�g���N�^
	*/
	InputDevice(const InputDevice &other){}

	/// ��{�����̕�����
	InputDevice &operator = (const InputDevice &other){}

public:

	/// �V���O���g���p�^�[��
	static InputDevice& GetInstance()
	{
		static InputDevice inputdevice;

		return inputdevice;
	}

	/// Input�̃C���^�[�t�F�C�X�𐶐�
	/**
	* @attention WinMain�֐���1��Ăׂ�OK
	* @retval S_OK		����������
	* @retval E_FAIL	���������s
	*/
	HRESULT InitInput();

	/// 
	/**
	* 
	* @attention
	* @param [in] _hWnd
	* @retval S_OK
	* @retval E_FAIL
	*/
	HRESULT InitInputKey(HWND _hWnd);
	HRESULT InitInputContlloer(HWND _hWnd);

	LPDIRECTINPUTDEVICE8 GetKeyDevice(){ return m_pKeyDevice; };
	LPDIRECTINPUTDEVICE8 GetContlloerDevice(){ return m_pContlloerDevice; };

};

#endif