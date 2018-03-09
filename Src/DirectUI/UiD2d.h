#ifndef UiD2d_h__
#define UiD2d_h__

#include <d2d1_1.h>
#include <dwrite.h>
#include <dxgi1_2.h>
#include <wrl.h>

using namespace Microsoft::WRL;

//d2d
typedef ComPtr<ID2D1Brush> ID2D1BrushPtr;
typedef ComPtr<ID2D1Bitmap> ID2D1BitmapPtr;
typedef ComPtr<ID2D1Bitmap1> ID2D1Bitmap1Ptr;
typedef ComPtr<ID2D1BitmapBrush> ID2D1BitmapBrushPtr;
typedef ComPtr<ID2D1Factory> ID2D1FactoryPtr;
typedef ComPtr<ID2D1Factory1> ID2D1Factory1Ptr;
typedef ComPtr<ID2D1HwndRenderTarget> ID2D1HwndRenderTargetPtr;
typedef ComPtr<ID2D1RenderTarget> ID2D1RenderTargetPtr;
typedef ComPtr<ID2D1SolidColorBrush> ID2D1SolidColorBrushPtr;
typedef ComPtr<ID2D1Device> ID2D1DevicePtr;
typedef ComPtr<ID2D1DeviceContext> ID2D1DeviceContextPtr;

//dwrite
typedef ComPtr<IDWriteFactory> IDWriteFactoryPtr;
typedef ComPtr<IDWriteTextFormat> IDWriteTextFormatPtr;

//dxgi
typedef ComPtr<IDXGIDevice> IDXGIDevicePtr;
typedef ComPtr<IDXGIDevice1> IDXGIDevice1Ptr;
typedef ComPtr<IDXGISurface> IDXGISurfacePtr;
typedef ComPtr<IDXGISurface1> IDXGISurface1Ptr;
typedef ComPtr<IDXGISwapChain> IDXGISwapChainPtr;
typedef ComPtr<IDXGISwapChain1> IDXGISwapChain1Ptr;

#endif // UiD2d_h__
