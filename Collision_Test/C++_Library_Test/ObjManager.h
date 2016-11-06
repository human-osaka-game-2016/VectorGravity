#include "BackGround.h"
#include "Robo.h"
#include "Robo2.h"

class ObjManager
{
private:

	Robo m_robo;
	BackGround m_bg;
	Robo2 m_robo2;

public:

	ObjManager();
	~ObjManager();

	virtual void Control();
	virtual void Draw();
};