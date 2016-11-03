#include "DirectDrawTexture.h"
#include "GraphicsDevice.h"

/* : �ȍ~�̓����o�C�j�V�����C�U�ƌ������̂ł��B
�킩��Ȃ��l�͒��ׂĂ�������
*/
Texture::Texture() : m_pTexture(NULL), m_pD3Device(GraphicsDevice::GetInstance().GetDevice())
{

}

// �f�X�g���N�^�Ȃ̂Ŏg�������̂�������Ă���
Texture::~Texture()
{
	Release();
}

// �e�N�X�`������ʂɒ���t����
void Texture::SetTexture(CUSTOMVERTEX _setdraw[])
{
	m_pD3Device->SetTexture(0, m_pTexture);

	m_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2,
		_setdraw, sizeof(CUSTOMVERTEX));
}

// �����̖��O�̉摜��ǂݍ���
HRESULT Texture::LoadTexture(const char _filePath[])
{
	if (FAILED(D3DXCreateTextureFromFile(m_pD3Device, _filePath, &m_pTexture)))
	{
		MessageBox(NULL, "�摜���ǂݍ��߂܂���ł����B", NULL, MB_OK);

		return E_FAIL;
	}

	return S_OK;
}

// �e�N�X�`���I�u�W�F�N�g��������Ă���
void Texture::Release()
{
	m_pTexture->Release();
}