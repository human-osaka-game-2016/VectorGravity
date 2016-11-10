/**
 * @file Player.h
 * @breif ��l���̃N���X�w�b�_�[
 * @author shibata
 */
/**
 * @file Player.h
 * @breif �L�����N�^�[�̎q�N���X�w�b�_�[
 * @author shibata
 */
#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

/// ��l���̃N���X
class Player : public Character
{
public:

	Player();
	virtual ~Player();

	virtual void Control();
	virtual void Draw();
	virtual void Attack();
	virtual void Move();

private:

	InputKeyBorad* m_pInputKey;
	RECT m_playerRect;

};


#endif // !PLAYER_H
