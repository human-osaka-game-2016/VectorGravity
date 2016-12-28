#include"Collider.h"

Collider::Collider(Collider::ColliderID idname_) :
m_isActive(true)
{
	m_ID = idname_;
}

Collider::~Collider()
{
}
