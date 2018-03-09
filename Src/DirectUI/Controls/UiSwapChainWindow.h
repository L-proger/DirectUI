#ifndef UiSwapChainWindow_h__
#define UiSwapChainWindow_h__

#include "UiNativeWindowBase.h"
#include "../Renderers/UiSwapChainRenderer.h"
#include "../UiD2d.h"

class UiSwapChainWindow : public UiNativeWindowBase {
public:
	static std::shared_ptr<UiSwapChainWindow> Create(const UiString& name);
	virtual UiRendererPtr GetRenderer() override;
	void Bind(IDXGIDevicePtr device, IDXGISurfacePtr backBuffer);
private:
	UiSwapChainWindow(const UiString& name);
	std::shared_ptr<UiSwapChainRenderer> _renderer;
};
#endif // UiSwapChainWindow_h__
