#ifndef STAGE1_H
#define STAGE1_H

#include <d3dx9.h>
#include <Vertex.h>
#include "Stage.h"

#define STAGE_HEIGHT 45
#define STAGE_WIDTH 200
#define BACKGROUND_HEIGHT 720
#define BACKGROUND_WIDTH 1280
#define CHIP_SIZE 32.f

class Texture;
class Vertex;

class Stage1 : public Stage
{
public:
	Stage1();
	~Stage1();

	virtual void Control();

	virtual void Draw();

	virtual int GetStageHeight()
	{
		return STAGE_HEIGHT;
	}

	virtual int GetStageWidth()
	{
		return STAGE_WIDTH;
	}

	virtual int** GetStageData();

	void StageLoad(const char*);

	void StageRelease();


private:

	int** m_stage;

	Texture* m_pTexture;
	Texture* m_pTexture2;
	Vertex*  m_pVertex;
	Vertex*  m_pVertex2;

	CUSTOMVERTEX m_mapchip[4];

	//Player‚ÌŒ»İˆÊ’u‚ğó‚¯æ‚é‚½‚ß‚Ìƒƒ“ƒo•Ï”
	float m_playerPosX;
	float m_playerPosY;

	//Player‚ÌˆÚ“®—Ê‚ğó‚¯æ‚é‚½‚ß‚Ìƒƒ“ƒo•Ï”
	float m_playerMovingDistanceX;
	float m_playerMovingDistanceY;

	D3DXVECTOR2 m_basePointDistance;
};

#endif // !STAGE1_H