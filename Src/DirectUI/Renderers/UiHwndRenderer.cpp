#include "UiHwndRenderer.h"

void UiHwndRenderer::Init(WindowPtr window) {
	UiRenderer::Init();

	uint32_t w, h;
	window->GetWindowSize(w, h);
	auto size = D2D1::Size(w, h);

	// Create a Direct2D render target.

	ID2D1HwndRenderTargetPtr hwndTarget;
	auto hr = m_pDirect2dFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(window->GetHwnd(), size),
		&hwndTarget
	);

	m_pRenderTarget = (ID2D1RenderTargetPtr)hwndTarget;
}

std::shared_ptr<UiHwndRenderer> UiHwndRenderer::Create() {
	return std::shared_ptr<UiHwndRenderer>(new UiHwndRenderer());
}