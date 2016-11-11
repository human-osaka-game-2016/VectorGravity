#include "StateManager.h"

StateManager::StateManager()
{

}

StateManager::~StateManager()
{

}

void StateManager::SetVectorDirection(VectorDirection direction_)
{
	m_vectoDirection = direction_;
}

VectorDirection StateManager::GetVectorDirection()
{
	return m_vectoDirection;
}