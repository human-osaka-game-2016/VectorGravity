/**
 * @file CharcterManager.h
 * @breif �L�����N�^�[���Ǘ�����N���X�̃w�b�_�[
 * @author shibata
 */

#ifndef CHARCTERMANAGER_H
#define CHARCTERMANAGER_H

class Charcter;

class CharcterManager
{
public:

	CharcterManager();
	~CharcterManager();

	void Control();
	void Draw();

private:

	Charcter* m_pCharcter;

};


#endif // !CHARCTERMANAGER_H
