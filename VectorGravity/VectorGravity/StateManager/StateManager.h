/**
 * @file	StateManager.h
 * @breif	ゲームすべての状態を管理するクラスヘッダ
 * @author	shibata
 */

#ifndef STATEMANAGER_H
#define STATEMANAGER_H

enum VectorDirection;
enum BulletKind;
enum Angle;

class StateManager
{
public:

	~StateManager();

	static StateManager& Instance()
	{
		static StateManager stateManager;

		return stateManager;
	}

	void SetPlayerHp(int playerHp_)
	{
		m_playerHpState = playerHp_;
	}

	void SetPlayerGp(int playerGp_)
	{
		m_playerGpState = playerGp_;
	}

	void PlayerRest(int playerRest_)
	{
		m_playerRestState = playerRest_;
	}

	void SetVectorDirection(VectorDirection vectorDirection_)
	{
		m_vectorDirectionState = vectorDirection_;
	}

	void SetVectorOperation(bool operation_)
	{
		m_bulltOperationState = operation_;
	}

	int GetPlayerHp()
	{
		return m_playerHpState;
	}

	int GetPlayerGp()
	{
		return m_playerGpState;
	}

	int GetPlayerRest()
	{
		return m_playerRestState;
	}

	VectorDirection GetVectorDirection()
	{
		return m_vectorDirectionState;
	}

private:
	StateManager();

	int					m_playerHpState;
	int					m_playerGpState;
	VectorDirection		m_vectorDirectionState;
	BulletKind			m_bulletKindState;
	Angle				m_angleState;
	bool				m_bulltOperationState;
	bool				m_gumBulletRestState;
	bool				m_penetratingBulletRestState;
	int					m_playerRestState;
	int					m_scoreState;
	int					m_bossHpState;

};

#endif // !STATEMANAGER_H