#ifndef UiNativeWindowBase_h__
#define UiNativeWindowBase_h__

#include <Windows.h>
#include <Windowsx.h>
#include "../Window.h"
#include "UiCoreWindow.h"

class UiNativeWindowBase : public UiCoreWindow {
public:
	UiNativeWindowBase(const UiString& name);
	virtual void Update(double dt) override;
	WindowPtr GetWindow() {
		return _window;
	}
protected:
	void WndMsgCallback(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	WindowPtr _window;
	int _width;
	int _height;
};
#endif // UiNativeWindowBase_h__
