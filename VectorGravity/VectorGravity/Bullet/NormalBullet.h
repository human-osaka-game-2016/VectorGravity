/**
 * @file	NormalBullet.h
 * @breif	通常弾のクラスヘッダ
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
	void Charge();	///@todo　Bulletにこの関数が必要なのか疑問なので後に要検討

};

#endif // !NORMALBULLET_H