#ifndef PAUSEBACKGROUND_H
#define PAUSEBACKGROUND_H

class Texture;
class Vertex;

class PauseBackground
{
public:
	PauseBackground();
	~PauseBackground();

	void Draw();

private:
	Texture*	m_pTexture;
	Vertex*		m_pVertex;
};

#endif // !PAUSEBACKGROUND_H