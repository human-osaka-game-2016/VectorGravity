#ifndef VECTORICON_H
#define VECTORICON_H

#include "Ui.h"

class VectorIcon : public Ui
{
public:

	VectorIcon();
	virtual ~VectorIcon();

	virtual void Draw();

private:
	void DrawIcon(float maxtu_, float maxtv_, float mintu_, float mintv_);

private:

	const float m_kiconPosX;
	const float m_kiconPosY;
	const float m_kiconSize;
	float		m_iconMaxTu;
	float		m_iconMinTu;
	float		m_iconMaxTv;
	float		m_iconMinTv;
};

#endif // !VECTORICON_H