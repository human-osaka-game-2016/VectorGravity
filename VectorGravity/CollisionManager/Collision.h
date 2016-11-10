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

	void SetObjectRect(RECT object1_)		//SetObjectRectは自キャラなどのControl関数の最後に置くことで、そのキャラの移動後の座標を毎フレーム取得することが出来ます。
	{
		//Objectには衝突する２つの物体を定義するため、名前は変更される可能性があります。
	}

private:
	Collision();

	RECT m_object1;			//Objectには衝突する２つの物体を定義するため、名前は変更される可能性があります。
	RECT m_object2;			//Objectには衝突する２つの物体を定義するため、名前は変更される可能性があります。
};

#endif // !COLLISION_H