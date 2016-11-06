#include "ObjManager.h"
#include "Obj.h"

ObjManager::ObjManager()
{
}

ObjManager::~ObjManager()
{
}

void ObjManager::Control()
{
	Obj* objcontrollist = &m_robo;

	objcontrollist->Control();

}

void ObjManager::Draw()
{
	Obj* objdrawlist[3] =
	{
		&m_bg, &m_robo, &m_robo2
	};


	for (int i = 0; i < 3; i++)
	{
		objdrawlist[i]->Draw();
	}
}