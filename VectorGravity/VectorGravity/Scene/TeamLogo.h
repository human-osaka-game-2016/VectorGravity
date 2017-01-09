/**
 * @file	TeamLogo
 * @breif	チームロゴのクラスヘッダ
 * @author	shibata
 */

#ifndef TEAMLOGO_H
#define TEAMLOGO_H

#define LOGO_WIDTH			512
#define LOGO_HEIGHT			512
#define LOGO_POSITIONX		640
#define LOGO_POSITIONY		360
#define ALPHA_MAX			255
#define LOGO_START_SECOND	60


class Texture;
class Vertex;

class TeamLogo
{
public:

	enum FadeState
	{
		FADE_IN,
		FADE_OUT
	};

	TeamLogo();
	~TeamLogo();

	bool Control();
	void Draw();

private:

	bool Fade();

	int			m_startTimer;
	int			m_alpha;
	FadeState	m_logoState;
	Texture*	m_pTexture;
	Vertex*		m_pVertex;

};

#endif // !TEAMLOGO_H