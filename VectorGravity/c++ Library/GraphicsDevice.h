/**
 * @file GraiphcsDevice.h
 * @breif DirectX�̃I�u�W�F�N�g��f�o�C�X�𐶐����Ă���
*/

#ifndef GRAPHICSDEVICE
#define GRAPHICSDEVICE

#include <d3dx9.h>

class GraphicsDevice
{
private:

	/**
	* �V���O���g���p�^�[�����g�p���Ă���̂ŃR���X�g���N�^��private�ɓ���Ă���
	*/
	GraphicsDevice(){}

	/**
	* �V���O���g���p�^�[���̂��߂̃R�s�[�R���X�g���N�^
	*/
	GraphicsDevice(const GraphicsDevice &other){}

	/**
	* �悭�������
	*/
	GraphicsDevice &operator = (const GraphicsDevice &other){}

	IDirect3D9*	m_pDirect3D;		//!< DirectX�̃I�u�W�F�N�g�̃|�C���^
	IDirect3DDevice9* m_pD3Device;	//!< DirectX�̃f�o�C�X�̃|�C���^
	D3DPRESENT_PARAMETERS m_d3dpp;	//!< �o�b�t�@�ݒ�ɕK�v�Ȃ��̂������͂�
	HWND m_hWnd;					//!< �E�B���h�n���h��

public:

	//!< �V���O���g���p�^�[��
	static GraphicsDevice& getInstance()
	{
		static GraphicsDevice graphicsDevice;
		
		return graphicsDevice;
	}

	/// DirectX�̃I�u�W�F�N�g�ƃf�o�C�X�̏������֐�
	/**
	* @param [in]	_hWnd �E�B���h�n���h��
	* @retval true	���������� 
	* @retval false ���������s 
	*/
	bool InitDirect(HWND _hWnd);

	/// �e�N�X�`���𒣂邽�߂̏�����
	/**
	* @attention InitDirect�ŌĂ�ł�����̂Ŋ֐����ĂԕK�v�͂Ȃ�
	*/
	void InitDraw();

	/// ���_�t�H�[�}�b�g��ݒ肷��֐�
	/**
	* ����cpp�Ńt�H�[�}�b�g��ݒ肵�Ȃ���΂Ȃ�Ȃ�
	*/
	void SetFVF(DWORD _fvf);

	/// �`����n�߂�Ƃ��̊֐�
	/**
	* �`��܂Ƃ߂Ă���Ƃ���łP��Ăׂ΂���
	*/
	void DrawStart();

	/// �`��̏I������Ƃ��̊֐�
	/**
	* �`����܂Ƃ߂Ă���Ƃ����1��Ăׂ΂���
	*/
	void DrawEnd();

	/// �f�o�C�X�����X�g�����Ƃ��̑Ώ��֐�
	/**
	* �f�o�C�X�����X�g���ꂽ�Ƃ��ɌĂ΂��
	*/
	bool DeviceLost();

	/// �f�o�C�X������1��擾����֐�
	/**
	* ���X�g�����Ƃ��ɌĂ΂��
	*/
	void ResetDevice();
	
	/// ���݂̃f�o�C�X�擾�֐�
	/**
	* @return DirectX�̃f�o�C�X�̃|�C���^
	*/
	IDirect3DDevice9* GetDevice();

};

#endif