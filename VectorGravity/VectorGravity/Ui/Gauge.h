#ifndef GAUGE_H
#define GAUGE_H

#include "Ui.h"

class Gauge : public Ui
{
public:

	Gauge();
	virtual ~Gauge();

	virtual void Draw();

private:

	void DrawFrame();	// ògÇÃï`âÊä÷êî
	void DrawHp();
	void DrawGp();

private:

	const float		m_gaugeWidth;
	const float		m_gaugeHeight;
	const float		m_hpFlamePosX;
	const float		m_hpFlamePosY;
	const float		m_gpFlamePosX;
	const float		m_gpFlamePosY;
	 float			m_hpGaugePosX;
	const float		m_hpGaugePosY;
	 float			m_gpGaugePosX;
	const float		m_gpGaugePosY;
	float			m_hpGaugeWidth;
	float			m_hpGaugeHeight;
	float			m_gpGaugeWidth;
	float			m_gpGaugeHeight;
	int				m_playerHp;
	int				m_playerGp;
};

#endif // !GAUGE_H