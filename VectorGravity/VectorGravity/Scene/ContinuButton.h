#ifndef CONTINUBUTTON_H
#define CONTINUBUTTON_H

class Texture;
class Vertex;

class ContinuButton
{
public:
	ContinuButton();
	~ContinuButton();

	void Draw();

private:
	Texture*		m_pTexture;
	Vertex*			m_pVertex;

	const float		m_kContinuButtonWidht;
	const float		m_kContinuButtonHeight;
	const float		m_kContinuButtonPosX;
	const float		m_kContinuButtonPosY;
};

#endif // !CONTINUBUTTON_H