#ifndef STAGE_H
#define STAGE_H

class Stage
{
public:

	Stage();
	virtual ~Stage();

	virtual void Draw() = 0;

	virtual void Control() = 0;

	virtual int GetStageHeight();

	virtual int GetStageWidth();

	virtual int** GetStageData();

};

#endif // !STAGE_H