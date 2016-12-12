/**
 * @file	main.cpp
 * @breif	エントリーポイント
 * @auhtor	shibata
 */

#include <Windows.h>
#include <crtdbg.h>
#include <mmsystem.h>
#include <GraphicsDevice.h>
#include <InputDevice.h>
#include <WindowCreate.h>
#include "Scene\SceneManager.h"

#pragma comment ( lib, "dsound.lib" )
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "Xinput.lib")

#define GAME_TITLE TEXT("ベクトルグラビティー")
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
	MSG msg;

	WindowCreate*	pWindowCreate;
	GraphicsDevice*	pGrapphicsDevice;
	InputDevice*	pInputDevice;
	SceneManager*	pSceneManager;

	pWindowCreate = new WindowCreate;
	pWindowCreate->Create(hinst, WindowProc, GAME_TITLE, DISPLAY_WIDTH, DISPLAY_HIGHT, false);

	pGrapphicsDevice = &GraphicsDevice::Instance();
	pGrapphicsDevice->InitDirect(pWindowCreate->GetHwnd(), DISPLAY_WIDTH, DISPLAY_HIGHT, false);

	pInputDevice = &InputDevice::Instance();
	pInputDevice->InitInput();
	pInputDevice->InitInputKey(pWindowCreate->GetHwnd());

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

	delete pWindowCreate;
	delete pSceneManager;

	return (INT)msg.wParam;
}