#include <Windows.h>
#include <crtdbg.h>
#include <mmsystem.h>
#include <DirectDrawTexture.h>
#include <InputDevice.h>

#include "SceneManager\SceneManager.h"

#define TITLE TEXT("ベクトルグラビティー")
#define DISPLAY_WIDTH 1280
#define DISPLAY_HIGHT 720
#define GAME_FPS (1000/60)

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
	case WM_DESTROY:

		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		switch ((CHAR)wparam)
		{
		case VK_ESCAPE:

			PostQuitMessage(0);
			break;
		}
		break;
	}
	return  DefWindowProc(hwnd, message, wparam, lparam);
}

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hprevinst, LPSTR szstr, INT icmshow)
{
	HWND hWnd;
	MSG msg;

	GraphicsDevice* pGraphicsDevice;
	InputDevice* pInputDevice;
	SceneManager* pSceneManager;

	// メモリリーク検出
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	WNDCLASSEX  wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WindowProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hinst;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = TITLE;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	hWnd = CreateWindow(
		TITLE,
		TITLE,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	
		CW_USEDEFAULT,						
		CW_USEDEFAULT,						
		DISPLAY_WIDTH,						
		DISPLAY_HIGHT,						
		NULL,
		NULL,
		hinst,						
		NULL);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	pGraphicsDevice = &GraphicsDevice::GetInstance();

	pGraphicsDevice->InitDirect(hWnd);
	pGraphicsDevice->InitDraw();

	pInputDevice = &InputDevice::GetInstance();

	pInputDevice->InitInput();
	pInputDevice->InitInputKey(hWnd);


	pSceneManager = new SceneManager;

	DWORD NowTime = timeGetTime();
	DWORD OldTime = timeGetTime();

	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			NowTime = timeGetTime();
			if (NowTime - OldTime >= GAME_FPS)
			{
				if (pSceneManager->Run())
				{
					break;
				}
				OldTime = timeGetTime();
			}
		}
	}

	delete pSceneManager;

	return (INT)msg.wParam;

}

