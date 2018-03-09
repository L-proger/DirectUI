#ifndef NativeWindow_h__
#define NativeWindow_h__

#include <Windows.h>
#include <memory>
#include <string>
#include "UiTypes.h"
#include <functional>
#include <locale>
#include <codecvt>

class Window {
public:
	BOOL Init(const UiString& name) {
		hInst = GetModuleHandle(NULL);;
		MyRegisterClass(hInst);

		hWnd = CreateWindowW(szWindowClass, name.c_str(), WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInst, NULL);

		if(!hWnd) {
			return FALSE;
		}
		SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)this);
		ShowWindow(hWnd, SW_SHOWNORMAL);
		UpdateWindow(hWnd);
		SetSize(640, 480);

		
		return TRUE;
	}

	virtual ~Window() {

	}

	void ProcessMessages() {
		MSG msg = { 0 };
		while(PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			switch(msg.message) {
			case WM_QUIT:
				exit(0);
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	HWND GetHwnd() {
		return hWnd;
	}

	void SetSize(int w, int h) {
		RECT NewWindowSize;
		NewWindowSize.top = 50;
		NewWindowSize.left = 50;
		NewWindowSize.bottom = NewWindowSize.top + h;
		NewWindowSize.right = NewWindowSize.left + w;

		AdjustWindowRect(&NewWindowSize, WS_OVERLAPPEDWINDOW, false);
		SetWindowPos(hWnd, HWND_TOP, NewWindowSize.left, NewWindowSize.top, NewWindowSize.right - NewWindowSize.left, NewWindowSize.bottom - NewWindowSize.top, SWP_SHOWWINDOW | SWP_FRAMECHANGED);
	}

	void GetWindowSize(uint32_t& width, uint32_t& height) {
		RECT r;
		GetClientRect(hWnd, &r);
		width = r.right - r.left;
		height = r.bottom - r.top;
	}

	uint32_t width() const{
		RECT r;
		GetClientRect(hWnd, &r);
		return r.right - r.left;
	}

	uint32_t height() const {
		RECT r;
		GetClientRect(hWnd, &r);
		return r.bottom - r.top;
	}

	std::function<void(HWND, UINT, WPARAM, LPARAM)> messageCallback = nullptr;
private:
	ATOM MyRegisterClass(HINSTANCE hInstance) {
		WNDCLASSEX wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = &Window::WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = hInstance;
		wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = szWindowClass;
		wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

		return RegisterClassEx(&wcex);
	}

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

		auto window = (Window*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
		if(window != nullptr && window->messageCallback) {
			window->messageCallback(hWnd, message, wParam, lParam);
		}
		switch(message) {
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		return 0;
	}
	
	HINSTANCE hInst;
	const TCHAR* szWindowClass = TEXT("Window");
	HWND hWnd;
};

typedef std::shared_ptr<Window> WindowPtr;
#endif // NativeWindow_h__
