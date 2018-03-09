#ifndef UiSwapChainRenderer_h__
#define UiSwapChainRenderer_h__

#include "../UiRenderer.h"
#include "../UiD2d.h"

class UiSwapChainRenderer : public UiRenderer {
public:
	void Init(WindowPtr window, IDXGIDevicePtr device, IDXGISurfacePtr surface);
	static std::shared_ptr<UiSwapChainRenderer> Create();
private:
	UiSwapChainRenderer();
	ID2D1DevicePtr _device;
	ID2D1DeviceContextPtr _context;
	ID2D1Bitmap1Ptr _bitmap;
};

#endif // UiSwapChainRenderer_h__
