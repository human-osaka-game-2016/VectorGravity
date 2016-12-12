/**
 * @file	NormalBullet.h
 * @breif	�ʏ�e�̃N���X�w�b�_
 * @author	shibata
 */

#ifndef NORMALBULLET_H
#define NORMALBULLET_H

#include "Bullet.h"

class NormalBullet : public Bullet
{
public:

	NormalBullet();
	~NormalBullet();

	virtual void Control();
	virtual void Draw();
	void Bound();
	void Charge();	///@todo�@Bullet�ɂ��̊֐����K�v�Ȃ̂��^��Ȃ̂Ō�ɗv����

};

#endif // !NORMALBULLET_H