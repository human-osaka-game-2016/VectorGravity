/**
 * @file	StageManager.h
 * @breif	�X�e�[�W���Ǘ�����N���X�w�b�_
 * @author	shibata
 */

#ifndef STAGEMANAGER_H
#define STAGEMANAGER_H

class Stage1;

class StageManager
{
public:

	StageManager();
	~StageManager();

	void Control();
	void Draw();

	Stage1* m_pStage1;

};

#endif // !STAGEMANAGER_H