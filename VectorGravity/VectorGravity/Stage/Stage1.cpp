#include "Stage1.h"
#include <stdio.h>
#include"../Collider/CollisionManager.h"
#include"../DataManager/DataManager.h"
#include<Vertex.h>
#include<Texture.h>

Stage1::Stage1() :
m_pTexture(new Texture),
m_pVertex(new Vertex)
{
	m_mapchip[0] = { 0.0f,           0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f };
	m_mapchip[1] = { CHIP_SIZE,      0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f };
	m_mapchip[2] = { CHIP_SIZE, CHIP_SIZE, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f };
	m_mapchip[3] = { 0.0f,      CHIP_SIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f };

	m_pTexture->LoadTexture("Resource/Texture/Block.png");
	m_pVertex->SetTextureSize(CHIP_SIZE, CHIP_SIZE);

	StageLoad("Resource/File/stage1.csv");	//ステージ１用

	CollisionManager::getInstance().SetStage(this);
}

Stage1::~Stage1()
{
	delete m_pTexture;
	delete m_pVertex;
}

void Stage1::Control()
{
	m_basePointDistance = DataManager::GetInstance().GetBasePointDistance();
}

void Stage1::StageLoad(const char* stagedata_)
{
	FILE*  fp;
	fopen_s(&fp, stagedata_, "r");

	m_stage = new int*[STAGE_HEIGHT];
	for (int i = 0; i < STAGE_HEIGHT; i++)
	{
		m_stage[i] = new int[STAGE_WIDTH];
	}

	for (int i = 0; i < STAGE_HEIGHT; i++)
	{
		for (int j = 0; j < STAGE_WIDTH; j++)
		{
			fscanf_s(fp, "%d,", &m_stage[i][j], sizeof(int));
			switch (m_stage[i][j])
			{
			case 51:
			{
				m_stage[i][j] = 0;
				D3DXVECTOR2 InitEnemyPos;
				InitEnemyPos.x = j * CHIP_SIZE;
				InitEnemyPos.y = i * CHIP_SIZE;
				DataManager::GetInstance().AddEnemyInitPos(InitEnemyPos);
			}
			break;
			case 101:
			{
				m_stage[i][j] = 0;
				D3DXVECTOR2 InitPlayerPos;
				InitPlayerPos.x = j * CHIP_SIZE;
				InitPlayerPos.y = i * CHIP_SIZE;
				DataManager::GetInstance().SetPlayerInitPos(InitPlayerPos);
			}
			break;
			case 201:
			{
				m_stage[i][j] = 0;
				D3DXVECTOR2 GoalPointPos;
				GoalPointPos.x = j * CHIP_SIZE;
				GoalPointPos.y = i * CHIP_SIZE;
				DataManager::GetInstance().SetGoalPointPos(GoalPointPos);
			}
			break;
			}
		}
	}
}

void Stage1::StageRelease()
{
	for (int i = 0; i < STAGE_HEIGHT; i++)
	{
		delete m_stage[i];
	}
	delete m_stage;
}

void Stage1::Draw()
{
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			if (m_stage[y][x] == 1)
			{
				CUSTOMVERTEX stagechip[4];
				for (int i = 0; i < 4; i++)
				{
					stagechip[i] = m_mapchip[i];
				}

				for (int i = 0; i < 4; i++)
				{
					stagechip[i].x += (x * CHIP_SIZE);
					stagechip[i].y += (y * CHIP_SIZE);

					stagechip[i].x -= m_basePointDistance.x;
					stagechip[i].y -= m_basePointDistance.y;
				}
				m_pVertex->DrawLeftTop(stagechip[0].x, stagechip[0].y, m_pTexture);
			}
		}
	}
}

int** Stage1::GetStageData()
{
	return m_stage;
}