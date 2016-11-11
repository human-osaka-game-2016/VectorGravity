/**
 * @file StateManager.h
 * @breif �Q�[���̑S�Ă̏�Ԃ��Ǘ�����N���X�̃w�b�_�[
 * @author shibata
 */

#ifndef STATEMANAGER_H
#define STATEMANAGER_H

enum VectorDirection;

class StateManager
{
public:

	~StateManager();

	static StateManager& GetInstance()
	{
		static StateManager stateManager;

		return stateManager;
	}

	void SetVectorDirection(VectorDirection direction_);
	VectorDirection GetVectorDirection();

private:

	StateManager();
	VectorDirection m_vectoDirection;

};

#endif // !STATEMANAGER_H
