#include "UiNativeWindowBase.h"

UiNativeWindowBase::UiNativeWindowBase(const UiString& name) :UiCoreWindow(name), _width(1280), _height(720){
	_window = std::shared_ptr<Window>(new Window());
	_window->Init(name);
	_window->SetSize(_width, _height);
	_window->messageCallback = std::bind(&UiNativeWindowBase::WndMsgCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
	//size.Width
}

void UiNativeWindowBase::Update(double dt) {
	int w = (int)size.Width.value;
	int h = (int)size.Height.value;

	if(w != _width || h != _height)
	{
		_width = w;
		_height = h;
		_window->SetSize(_width, _height);
	}

	UiCoreWindow::Update(dt);
	_window->ProcessMessages();
}

void UiNativeWindowBase::WndMsgCallback(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_MOUSEMOVE:
	{
		auto msg = std::make_shared<UiInputMessage>();
		msg->type = UiInputMessageType::MouseMove;
		UiInputManager::mouseCoord.x = (float)GET_X_LPARAM(lParam);
		UiInputManager::mouseCoord.y = (float)GET_Y_LPARAM(lParam);
		PushMessage(msg);
	}
	break;
	case WM_MOUSEWHEEL:
	{
		auto msg = std::make_shared<UiInputMessage>();
		msg->type = UiInputMessageType::MouseVWheel;
		msg->param = GET_WHEEL_DELTA_WPARAM(wParam);
		PushMessage(msg);
	}
	break;
	case WM_MOUSEHWHEEL:
	{
		auto msg = std::make_shared<UiInputMessage>();
		msg->type = UiInputMessageType::MouseHWheel;
		msg->param = GET_WHEEL_DELTA_WPARAM(wParam);
		PushMessage(msg);
	}
	break;
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_MBUTTONDOWN:
	{
		auto msg = std::make_shared<UiInputMessage>();
		msg->type = UiInputMessageType::MouseButtonDown;
		msg->param = message == WM_LBUTTONDOWN ? 0 : (message == WM_RBUTTONDOWN ? 1 : 2);
		PushMessage(msg);
	}
	break;
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MBUTTONUP:
	{
		auto msg = std::make_shared<UiInputMessage>();
		msg->type = UiInputMessageType::MouseButtonUp;
		msg->param = message == WM_LBUTTONUP ? 0 : (message == WM_RBUTTONUP ? 1 : 2);
		PushMessage(msg);
	}
	break;
	break;
	default:
		break;
	}
}