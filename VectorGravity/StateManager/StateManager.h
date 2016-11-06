/**
 * @file StateManager.h
 * @breif ゲームの全ての状態を管理するクラスのヘッダー
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
