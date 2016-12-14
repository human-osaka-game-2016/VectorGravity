#ifndef TANK_H
#define TANK_H

#include <Vertex.h>
#include "Enemy.h"

#define TANKWIDTH 256
#define TANKHEIGHT 192
#define MOVE_SPEED 10

class Vertex;
class InputKey;

class Tank : public Enemy
{
public:
	Tank();
	~Tank();

	virtual void Control();
	virtual void Draw();

private:

	InputKey* m_pInputKey;
	Vertex* m_pVertex;
};

#endif // !TANK_H