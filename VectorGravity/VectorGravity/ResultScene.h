
#ifndef RESULTSCENESCENE_H
#define RESULTSCENESCENE_H

#include "Scene.h"

class ResultScene : public Scene
{
public:
	ResultScene();
	virtual ~ResultScene();

	virtual SceneID Control();
	virtual void Draw();
};

#endif // !LOGOSCENE_H
