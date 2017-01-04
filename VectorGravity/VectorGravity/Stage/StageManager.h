/**
 * @file	StageManager.h
 * @breif	ステージを管理するクラスヘッダ
 * @author	shibata
 */

#ifndef STAGEMANAGER_H
#define STAGEMANAGER_H

class Stage1;
class GoalPoint;

class StageManager
{
public:

	StageManager();
	~StageManager();

	void Control();
	void Draw();

	Stage1*    m_pStage1;
	GoalPoint* m_pGoalPoint;

};

#endif // !STAGEMANAGER_H