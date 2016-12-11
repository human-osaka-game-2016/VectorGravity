/**
 * @file	TextureManager.h
 * @breif	�e�N�X�`�����Ǘ������Ă���N���X�w�b�_
 * @author	shibata
 */

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <vector>

class Texture;

class TextureManager
{
public:

	TextureManager();
	~TextureManager();

	/**
	* �摜�̓ǂݍ���
	* @param [in]	index_		�ǂ��̔z��ԍ��̃e�N�X�`����	(���쑤��enum�����g���Ĕ��f������)
	* @param  [in]	filepath_	�摜�t�@�C���̃p�X
	*/
	void LoadTexture(int index_, const char* filepath_);

	/**
	* �ڍׂȉ摜�̓ǂݍ���
	* @param [in]	index_		�ǂ��̔z��ԍ��̃e�N�X�`����	(���쑤��enum�����g���Ĕ��f������)
	* @param [in]	filepath_	�摜�t�@�C���̃p�X
	* @param [in]	alpha_		�摜�̓��ߒl		�f�t�H���g��255
	* @param [in]	red_		�摜��R�l			�f�t�H���g��0
	* @param [in]	green_		�摜��G�l			�f�t�H���g��0
	* @param [in]	blue_		�摜��B�l			�f�t�H���g��0
	* @param [in]	istexsize_	2�̗ݏ悩�ǂ���	�f�t�H���g��true
	*/
	void LoadTextureEX(int index_, const char* filepath_, int alpha_, int red_, int green_, int blue_, bool istexsize_);

	/**
	 * �e�N�X�`���f�[�^�̏��擾�֐�
	 * @param [in] index_ �ق����e�N�X�`���f�[�^�̔z��ԍ�
	 * @return m_pTexture[index_]->GetTextureData()
	 */
	LPDIRECT3DTEXTURE9 GetTextureData(int index_)
	{
		return m_pTexture[index_]->GetTextureData();
	}


private:

	std::vector<Texture*>		m_pTexture;

};

#endif // !TEXTUREMANAGER_H
