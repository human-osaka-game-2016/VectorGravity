#ifndef STAFFLOGO_H
#define STAFFLOGO_H

class Texture;
class Vertex;

class StaffLogo
{
public:
	StaffLogo();
	~StaffLogo();

	void Control();
	void Draw();

private:
	void Fade();

private:
	Texture*		m_pTexture;
	Vertex*			m_pVertex;

	const float		m_kStaffLogoWidht;
	const float		m_kStaffLogoHeight;
	const float		m_kStaffLogoPosX;
	const float		m_kStaffLogoPosY;
	int				m_LogoAlpha;
	int				m_fadeLogoTime;

};

#endif // !STAFFLOGO_H