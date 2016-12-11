/**
 * @file	VertexManaer.h
 * @breif	���_�����Ǘ����Ă���N���X�w�b�_
 * @author	shibata
 */

#ifndef VERTEXMANAGER_H
#define VERTEXMANAGER_H

#include <d3dx9.h>
#include <vector>

class Vertex;

class VertexManager
{
public:

	VertexManager();
	~VertexManager();

	/**
	* �e�N�X�`���T�C�Y���w�肷��֐�
	* @param [in] width_	�e�N�X�`���̕�
	* @param [in] height_	�e�N�X�`���̍���
	* @param [in] maxtu_	�e�N�X�`���̍ő�x���W
	* @param [in] maxtv_	�e�N�X�`���̍ő�y���W
	* @param [in] mintu_	�e�N�X�`���̍ŏ�x���W
	* @param [in] mintv_	�e�N�X�`���̍ŏ�y���W
	*/
	void SetTextureSize(float width_, float height_, float maxtu_, float maxtv_, float mintu_, float mintv_);

	/**
	* ���ォ��`�悷��֐�
	* @param [in] posx_		������W��x���̒l
	* @param [in] posy_		������W��y���̒l
	* @param [in] pTexture_	���݂̃e�N�X�`�����
	*/
	void DrawLeftTop(float posx_, float posy_, LPDIRECT3DTEXTURE9 pTexture_);

	/**
	* ���S����`�悷��֐�
	* @param [in] posx_		���S���W��x���̒l
	* @param [in] posy_		���S���W��y���̒l
	* @param [in] pTexture_	���݂̃e�N�X�`�����
	*/
	void DrawCenter(float posx_, float posy_, LPDIRECT3DTEXTURE9 pTexture_);

private:

	std::vector<Vertex*>	m_pVertex;
};

#endif // !VERTEXMANAGER_H
