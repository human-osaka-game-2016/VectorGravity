#ifndef MYRECT_H
#define MYRECT_H

class MyRect
{
public:
	MyRect();
	MyRect(float left_, float top_, float right_, float bottom_);
	~MyRect();

	float left;
	float top;
	float right;
	float bottom;

private:

};

#endif // !MYRECT_H