#ifndef COLLISION_H
#define COLLISION_H

#include <windows.h>

class Collision
{
public:
	bool Check();

	static Collision& getInstance()
	{
		static Collision collision;

		return collision;
	}

	~Collision();

	void SetObjectRect(RECT object1_)		//SetObjectRect�͎��L�����Ȃǂ�Control�֐��̍Ō�ɒu�����ƂŁA���̃L�����̈ړ���̍��W�𖈃t���[���擾���邱�Ƃ��o���܂��B
	{
		//Object�ɂ͏Փ˂���Q�̕��̂��`���邽�߁A���O�͕ύX�����\��������܂��B
	}

private:
	Collision();

	RECT m_object1;			//Object�ɂ͏Փ˂���Q�̕��̂��`���邽�߁A���O�͕ύX�����\��������܂��B
	RECT m_object2;			//Object�ɂ͏Փ˂���Q�̕��̂��`���邽�߁A���O�͕ύX�����\��������܂��B
};

#endif // !COLLISION_H