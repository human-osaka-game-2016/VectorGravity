#ifndef GOALPOINT_H
#define GOALPOINT_H

#include "../MyRect.h"
#include "../Collider/Collider.h"
#include "../MyRect.h"
#include <d3dx9.h>

#define GOALPOINTHEIGHT 256
#define GOALPOINTWIDTH  128

class Vertex;
class Texture;
class Collider;

class GoalPoint
{
public:
	GoalPoint(D3DXVECTOR2);
	~GoalPoint();

	void Control();
	void Draw();

private:

	MyRect m_GoalPointRect;
	MyRect m_baseRect;
	D3DXVECTOR2 m_base;
	Collider* m_pCollider;
	std::vector<Collider::ColliderID> m_colliderIDs;

	float m_posX;
	float m_posY;

	Vertex*  m_pVertex;
	Texture* m_pTexture;
};

#endif // !GOALPOINT_H