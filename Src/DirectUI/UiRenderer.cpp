#include "UiRenderer.h"

IDWriteFactoryPtr UiRenderer::m_pDWriteFactory = nullptr;
ID2D1FactoryPtr UiRenderer::m_pDirect2dFactory = nullptr;

void UiRenderer::Init() {
	if (m_pDWriteFactory == nullptr) {
		D2D1_FACTORY_OPTIONS options;
		options.debugLevel = D2D1_DEBUG_LEVEL_INFORMATION;
		auto hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, options, (ID2D1Factory**)&m_pDirect2dFactory);
	}

	if (m_pDWriteFactory == nullptr) {
		auto hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(m_pDWriteFactory), (IUnknown**)&m_pDWriteFactory);
	}
}

ID2D1RenderTargetPtr UiRenderer::GetRenderTarget() {
	return m_pRenderTarget;
}

void UiRenderer::BeginDraw() {
	m_pRenderTarget->BeginDraw();
	m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Gray));
}

void UiRenderer::EndDraw() {
	auto hr = m_pRenderTarget->EndDraw();
}

ID2D1FactoryPtr UiRenderer::GetFactory() {
	return m_pDirect2dFactory;
}

IDWriteFactoryPtr UiRenderer::GetWriteFactory() {
	return m_pDWriteFactory;
}