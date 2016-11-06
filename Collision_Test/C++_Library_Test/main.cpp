#include <windows.h>
#include <tchar.h>
#include <mmsystem.h>
#include <DirectDrawTexture.h>
#include <GraphicsDevice.h>
#include <DirectInput.h>
#include "Model.h"


#define DISPLAY_WIDTH 1280
#define DISPLAY_HIGHT 720
//#define MOVE_SPEED 5.f
#define GAME_FPS (1000/60)

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d9.lib")

#pragma comment(lib, "dxguid.lib")


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

	GraphicsDevice* pgraphicsdevice;
	InputDevice* pinputdevice;
	Model* pmodel;

	static TCHAR* titlename = _T("�v���g�^�C�v");
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
		titlename,								//�E�B���h�E�̃N���X��
		titlename, 							//�E�B���h�E�̃^�C�g��
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	//�E�B���h�E�X�^�C��
		CW_USEDEFAULT,						// �E�B���h�E�̉������̈ʒux
		CW_USEDEFAULT,						// �E�B���h�E�̏c�����̈ʒuy
		DISPLAY_WIDTH,							// Width�i���j
		DISPLAY_HIGHT,							// Height�i�����j
		NULL,
		NULL,
		hinst,							// �A�v���P�[�V�����C���X�^���X�̃n���h��
		NULL);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	pgraphicsdevice = &GraphicsDevice::getInstance();

	pgraphicsdevice->InitDirect(hWnd);

	pinputdevice = &InputDevice::GetInstance();

	pinputdevice->InitInput();
	pinputdevice->InitInputKey(hWnd);


	SetWindowText(hWnd, _T("�v���g�^�C�v"));

	pmodel = new Model;

	DWORD NowTime = timeGetTime();
	DWORD OldTime = timeGetTime();

	// ���b�Z�[�W���[�v
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
				if (!pmodel->Run())
				{
					break;
				}
				OldTime = timeGetTime();
			}
		}
	}

	delete pmodel;

	return (INT)msg.wParam;

}