#include <windows.h>
#include "temp.h"

#pragma comment(lib, "CandlelightEngine.lib")

using namespace Candlelight::TypeDefs;
using namespace Candlelight::Dependencies;

HINSTANCE hInst = nullptr;
HWND hWnd = nullptr;

HRESULT InitWindow(HINSTANCE pHInstance, int pNCmdShow);

int WINAPI wWinMain(_In_ const HINSTANCE pHInstance, _In_opt_ const HINSTANCE pHPrevInstance, _In_ const LPWSTR pLpCmdLine, _In_ const int pNCmdShow)
{
	UNREFERENCED_PARAMETER(pHPrevInstance);
	UNREFERENCED_PARAMETER(pLpCmdLine);

	if (FAILED(InitWindow(pHInstance, pNCmdShow)))
	{
		return 0;
	}

	//Get window height and width for scene manager
	RECT rc;
	GetClientRect(hWnd, &rc);
	float width = static_cast<float>(rc.right - rc.left);
	float height = static_cast<float>(rc.bottom - rc.top);

	//Main message loop
	MSG msg = { 0 };
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			sPtr<Temp> sPtr = std::make_shared<Temp>();
			uPtr<Temp> uPtr = std::make_unique<Temp>();
			wPtr<Temp> wPtr = sPtr;
		}
	}

	return static_cast<int>(msg.wParam);
}

LRESULT CALLBACK WndProc(const HWND hWnd, const UINT message, const WPARAM wParam, const LPARAM lParam)
{
	return DefWindowProc(hWnd, message, wParam, lParam);
}

HRESULT InitWindow(const HINSTANCE pHInstance, const int pNCmdShow)
{
	//Register class
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = pHInstance;
	wcex.hIcon = LoadIcon(pHInstance, nullptr);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = nullptr;
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = L"Game";
	wcex.hIconSm = LoadIcon(wcex.hInstance, nullptr);
	if (!RegisterClassEx(&wcex))
	{
		return static_cast<HRESULT>(0x80004005L);
	}

	//Create window
	hInst = pHInstance;
	RECT rc = { 0, 0, 1920, 1080 };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	hWnd = CreateWindow(L"Game", L"Game",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, pHInstance,
		nullptr);
	if (!hWnd)
	{
		return static_cast<HRESULT>(0x80004005L);
	}

	ShowWindow(hWnd, pNCmdShow);

	return static_cast<HRESULT>(0L);
}