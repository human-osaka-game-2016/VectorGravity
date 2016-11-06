#ifndef Model_H
#define Model_H

#include <DirectDrawTexture.h>
#include <DirectInput.h>
#include "ObjManager.h"

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

class Model
{
private:

	GraphicsDevice* m_graphicsdevice;
	InputDevice* m_inputdevice;
	InputKeyBorad* m_inputkeydevice;
	ObjManager m_objmanager;

public:

	Model();
	~Model();

	bool Run();

	void Control();
	void Render();

};

#endif 