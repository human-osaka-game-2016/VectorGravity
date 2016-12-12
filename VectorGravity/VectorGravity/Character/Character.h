/**
* @file		Character.h
* @breif	�L�����N�^�[�̐e�N���X�w�b�_
* @author	shibata
*/

#ifndef CHARCTER_H
#define CHARCTER_H

class Texture;

class Character
{
public:

	Character();
	virtual ~Character();

	virtual void Control() = 0;
	virtual void Draw() = 0;

protected:

	Texture*	m_pTexture;
	float		m_posX;
	float		m_posY;
	bool		m_isDeath;

};

#endif // !CHARCTER_H