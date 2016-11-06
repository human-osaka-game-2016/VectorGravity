/**
 * @file StateManager.h
 * @breif �Q�[���̑S�Ă̏�Ԃ��Ǘ�����N���X�̃w�b�_�[
 * @author shibata
 */

#ifndef STATEMANAGER_H
#define STATEMANAGER_H

class StateManager
{
public:

	~StateManager();

	static StateManager& Instance()
	{
		static StateManager stateManager;

		return stateManager;
	}

private:

	StateManager();

};

#endif // !STATEMANAGER_H
