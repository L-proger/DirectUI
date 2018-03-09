#include "UiHwndCoreWindow.h"

std::shared_ptr<UiHwndCoreWindow> UiHwndCoreWindow::Create(const UiString& name) {
	return std::make_shared<UiHwndCoreWindow>(name);
}

UiHwndCoreWindow::UiHwndCoreWindow(const UiString& name): UiNativeWindowBase(name) {
	_renderer = UiHwndRenderer::Create();
	_renderer->Init(_window);
}
void UiHwndCoreWindow::Render() {
	_renderer->BeginDraw();
	((UiControl*)this)->Render(_renderer);
	_renderer->EndDraw();
}
UiRendererPtr UiHwndCoreWindow::GetRenderer() {
	return _renderer;
}

void UiHwndCoreWindow::Update(double dt) {
	_window->ProcessMessages();
	uint32_t w, h;
	_window->GetWindowSize(w, h);
	size.Width = (float)w;
	size.Height = (float)h;
	UiCoreWindow::Update(dt);
}

void UiHwndCoreWindow::LockInput() {
	SetCapture(_window->GetHwnd());
}

void UiHwndCoreWindow::UnlockInput() {
	ReleaseCapture();
}

