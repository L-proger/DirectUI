#ifndef UiRenderer_h__
#define UiRenderer_h__

#include <d2d1.h>
#include "UiTypes.h"
#include <cstdint>
#include <dwrite.h>
#include "Window.h"

#pragma comment (lib, "dwrite.lib")
#pragma comment (lib, "d2d1.lib")

class UiRenderer {
public:
	void BeginDraw();
	void EndDraw();
	static ID2D1FactoryPtr GetFactory();
	ID2D1RenderTargetPtr GetRenderTarget();
	static IDWriteFactoryPtr GetWriteFactory();
protected:
	static void Init();
	static IDWriteFactoryPtr m_pDWriteFactory;
	static ID2D1FactoryPtr m_pDirect2dFactory;
	ID2D1RenderTargetPtr m_pRenderTarget;
};
#endif // Renderer_h__
