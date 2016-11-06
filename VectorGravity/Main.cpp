#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <mmsystem.h>
#include <../c++ Library/DirectDrawTexture/DirectDrawTexture.h>
#include <../c++ Library/Input/InputDevice/InputDevice.h>

#include "SceneManager\SceneManager.h"

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

	static TCHAR* titlename = _T("ベクトルグラビティー");
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
	wndclass.lpszClassName = titlename;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	hWnd = CreateWindow(
		titlename,						
		titlename, 							
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

	pInputDevice = &InputDevice::GetInstance();

	pInputDevice->InitInput();
	pInputDevice->InitInputKey(hWnd);

	SetWindowText(hWnd, _T("ベクトルグラビティー"));

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

