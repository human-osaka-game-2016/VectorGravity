/**
* @file		SceneManager.h
* @breif	シーン管理しているクラスヘッダ
* @author	shibata
*/

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

class GraphicsDevice;
class InputDevice;
class InputKey;
class InputContlloer;
class Scene;
enum SceneID;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Control();
	void Render();
	bool Run();

private:

	enum State
	{
		CREATE,
		RUN,
		RELEASE,
	};

	Scene*				m_pScene;
	InputDevice*		m_pInputDevice;
	GraphicsDevice*		m_pGraphicsDevice;
	InputKey*			m_pInputKey;
	InputContlloer*		m_pInputContlloer;
	State				m_state;
	SceneID				m_currentSceneID;
	SceneID				m_nextSceneID;
	bool				m_isGameEnd;

};

#endif // !SCENEMANAGER_H