#include "UiSwapChainWindow.h"

UiSwapChainWindow::UiSwapChainWindow(const UiString& name) : UiNativeWindowBase(name) {
	_renderer = UiSwapChainRenderer::Create();
}

std::shared_ptr<UiSwapChainWindow> UiSwapChainWindow::Create(const UiString& name) {
	return std::shared_ptr<UiSwapChainWindow>(new UiSwapChainWindow(name));
}

UiRendererPtr UiSwapChainWindow::GetRenderer() {
	return _renderer;
}
void UiSwapChainWindow::Bind(IDXGIDevicePtr device, IDXGISurfacePtr backBuffer) {
	_renderer->Init(_window, device, backBuffer);
}