/**
* @file		ObjectManager.h
* @breif	�S�ẴI�u�W�F�N�g���Ǘ�����N���X�w�b�_
* @author	shibata
*/

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

class StageManager;
class CharacterManager;
class BasePoint;
class UiManager;

enum VectorDirection
{
	VECTOR_UP,
	VECTOR_DOWN,
	VECTOR_LEFT,
	VECTOR_RIGHT
};

enum SoundKind
{
	PLAYER_ATTACK,
	VECTOR_CHANGE,
	PLAYER_DAMAGE,
	PLAYER_JUMP,
	PLAYER_GPRECOVER,
	PLAYER_LAND,		// Land = ���n
};

class ObjectManager
{
public:

	ObjectManager();
	~ObjectManager();

	void Control();
	void Draw();

private:

	StageManager*		m_pStageManager;
	CharacterManager*	m_pCharacterManager;
	BasePoint*			m_pBasePoint;
	UiManager*			m_pUiManager;

};

#endif // !OBJECTMANAGER_H