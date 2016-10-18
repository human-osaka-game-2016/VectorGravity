/**
* @file DirectDrawTexture.h
* @breif �e�N�X�`����`�悷�邽�߂�
*/


#ifndef DRAWTEXTURE
#define DRAWTEXTURE

#include "GraphicsDevice.h"


struct CUSTOMVERTEX
{
	FLOAT x, y, z, rhw;
	DWORD color;
	FLOAT tu, tv;
};

class Texture
{
private:

	LPDIRECT3DTEXTURE9 m_pTexture;	//!< �e�N�X�`���I�u�W�F�N�g�̃|�C���^
	IDirect3DDevice9* m_pD3Device;	//!< DirectX�̃f�o�C�X�̃|�C���^

public:

	Texture();
	~Texture();

	/// �e�N�X�`������ʂɒ���t����
	/**
	* @attention ���ꂾ���ł͉�ʂɉf��Ȃ�
	* @param [in] _setdraw �͂����摜�̍��W�T�C�Y
	*/
	void SetTexture(CUSTOMVERTEX _setdraw[]);

	/// �摜�ǂݍ���
	/**
	* �ȒP�ȉ摜�̓ǂݍ���
	* @param [in] _filePath[] �ǂݍ��މ摜�̖��O
	* @retval S_OK		�ǂݍ��ސ���
	* @retval E_FAIL	�ǂݍ��ݎ��s
	*/
	HRESULT LoadTexture(const char _filePath[]);

	/// �摜�ǂݍ���
	/**
	* �ڍׂȉ摜�̓ǂݍ���
	* @param [in] _filePath[] �ǂݍ��މ摜�̖��O
	* @param [in] _alpha �ǂݍ��މ摜�̃A���t�@�̒l
	* @param [in] _red �ǂݍ��މ摜�̐Ԃ̒l
	* @param [in] _green �ǂݍ��މ摜�̗΂̒l
	* @param [in] _bule �ǂݍ��މ摜�̐̒l
	* @retval S_OK		
	* @retval E_FAIL	
	*/
	HRESULT LoadTextureEX(const char _filePath[], int _alpha, int _red, int _green, int _blue);

	/// �e�N�X�`���I�u�W�F�N�g�̉��
	/**
	* @retrun �Ȃ�
	*/
	void Release();

	//LPDIRECT3DTEXTURE9 Get() { return m_pTexture; }

};

#endif