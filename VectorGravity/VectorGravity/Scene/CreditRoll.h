#ifndef CREDITROLL_H
#define CREDITROLL_H

class Texture;
class Vertex;

class CreditRoll
{
public:
	CreditRoll();
	~CreditRoll();

	void Control();
	void Draw();

private:
	Texture*		m_pTexture;
	Vertex*			m_pVertex;


	const float		m_kRollWidth;
	const float		m_kRollHeight;
	const float		m_kRollPosX;
	 float			m_kRollPosY;
};

#endif // !CREDITROLL_H