/**
 * @file Character.h
 * @breif �S�ẴL�����N�^�[�̐e�N���X�w�b�_�[
 * @author shibata
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <../c++ Library/DirectDrawTexture/DirectDrawTexture.h>

class Character
{
public:
	Character();
	virtual ~Character();

	virtual void Control() = 0;
	virtual void Draw() = 0;
	virtual void Attack() = 0;
	virtual void Move() = 0;

private:

	GraphicsDevice* m_pGraphicsDevice;
};

#endif // !CHARACTER_H


