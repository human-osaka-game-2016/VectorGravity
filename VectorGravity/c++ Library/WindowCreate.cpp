/**
 * @file	WindowCreate.cpp
 * @breif	ウィンドウ生成のクラス実装内部
 * @author	shibata
 */

#include "WindowCreate.h"

WindowCreate::WindowCreate() : 
m_hWnd(NULL)
{

}

WindowCreate::~WindowCreate()
{

}

void WindowCreate::Create(HINSTANCE hinstance_, LRESULT CALLBACK WindowProc_(HWND, UINT, WPARAM, LPARAM), TCHAR* titlename_, int clientwidth_, int clientheiht_, bool isfullscreen_)
{
	m_clientWidth = clientwidth_;
	m_clientHeiht = clientheiht_;

	m_windowClass.cbSize			=	sizeof(m_windowClass);
	m_windowClass.style				=	CS_HREDRAW | CS_VREDRAW;
	m_windowClass.lpfnWndProc		=	WindowProc_;
	m_windowClass.cbClsExtra		=	0;
	m_windowClass.cbWndExtra		=	0;
	m_windowClass.hInstance			=	hinstance_;
	m_windowClass.hIcon				=	LoadIcon(NULL, IDI_APPLICATION);
	m_windowClass.hCursor			=	LoadCursor(NULL, IDC_ARROW);
	m_windowClass.hbrBackground		=	(HBRUSH)GetStockObject(BLACK_BRUSH);
	m_windowClass.lpszMenuName		=	NULL;
	m_windowClass.lpszClassName		=	titlename_;
	m_windowClass.hIconSm			=	LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&m_windowClass);

	if (isfullscreen_)
	{
		m_hWnd = CreateWindow(
			titlename_,
			titlename_,
			WS_POPUP | WS_VISIBLE,			
			0,								
			0,								
			m_clientWidth,						
			m_clientHeiht,						
			NULL,
			NULL,
			hinstance_,
			NULL
			);
	}
	else
	{
		m_hWnd = CreateWindow(
			titlename_,
			titlename_,
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,	
			CW_USEDEFAULT,						
			CW_USEDEFAULT,					
			m_clientWidth,						
			m_clientHeiht,						
			NULL,
			NULL,
			hinstance_,
			NULL
			);

		RECT clientRect;

		GetClientRect(m_hWnd, &clientRect);

		m_clientWidth = m_clientWidth + (m_clientWidth - clientRect.right);
		m_clientHeiht = m_clientHeiht + (m_clientHeiht - clientRect.bottom);

		MoveWindow(
			m_hWnd,
			0,
			0,
			m_clientWidth,
			m_clientHeiht,
			TRUE
			);
	}

	ShowWindow(m_hWnd, SW_SHOW);

	UpdateWindow(m_hWnd);
}