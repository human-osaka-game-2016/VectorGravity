/**
 * @file CharcterManager.h
 * @breif �L�����N�^�[���Ǘ�����N���X�̃w�b�_�[
 * @author shibata
 */

#ifndef CHARACTERMANAGER_H
#define CHARACTERMANAGER_H

class Player;
class Tank;

class CharacterManager
{
public:

	CharacterManager();
	~CharacterManager();

	void Control();
	void Draw();

private:

	Player*		m_pPlayer;
	Tank* m_pTank;

};


#endif // !CHARACTERMANAGER_H
