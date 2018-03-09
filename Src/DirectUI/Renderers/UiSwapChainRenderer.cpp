#include "UiSwapChainRenderer.h"
#include <Windows.h>
#include <d2d1_1helper.h>

void UiSwapChainRenderer::Init(WindowPtr window, IDXGIDevicePtr device, IDXGISurfacePtr surface) {
	UiRenderer::Init();

	ID2D1Factory1Ptr factory1;
	m_pDirect2dFactory.As(&factory1);

	auto hr = factory1->CreateDevice(device.Get(), &_device);

	hr = _device->CreateDeviceContext(D2D1_DEVICE_CONTEXT_OPTIONS_NONE, &_context);

	D2D1_PIXEL_FORMAT pixelFormat;
	pixelFormat.format = DXGI_FORMAT_B8G8R8A8_UNORM;
	pixelFormat.alphaMode = D2D1_ALPHA_MODE_IGNORE;

	D2D1_BITMAP_PROPERTIES1 bitmapProperties;
	bitmapProperties.bitmapOptions = D2D1_BITMAP_OPTIONS_TARGET | D2D1_BITMAP_OPTIONS_CANNOT_DRAW;
	bitmapProperties.dpiX = 96.0f;
	bitmapProperties.dpiY = 96.0f;
	bitmapProperties.pixelFormat = pixelFormat;
	bitmapProperties.colorContext = NULL;

	hr = _context->CreateBitmapFromDxgiSurface(surface.Get(), bitmapProperties, &_bitmap);

	_context->SetTarget(_bitmap.Get());
}
std::shared_ptr<UiSwapChainRenderer> UiSwapChainRenderer::Create() {
	return std::shared_ptr<UiSwapChainRenderer>(new UiSwapChainRenderer());
}
UiSwapChainRenderer::UiSwapChainRenderer() {

}