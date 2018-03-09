#ifndef UiBitmap_h__
#define UiBitmap_h__

#include <d2d1.h>
#include "../UiRenderer.h"
#include <cstdint>

class UiBitmap {
public:
	ID2D1BitmapPtr GetBitmap();
	static std::shared_ptr<UiBitmap> Create(UiRendererPtr renderer, uint32_t width, uint32_t height, D2D1_PIXEL_FORMAT format);
	static std::shared_ptr<UiBitmap> Create(ID2D1BitmapPtr bitmap);
protected:
	UiBitmap(UiRendererPtr renderer, uint32_t width, uint32_t height, D2D1_PIXEL_FORMAT format);
	UiBitmap(ID2D1BitmapPtr bitmap);
private:
	ID2D1BitmapPtr _bitmap;
};
#endif // UiBitmap_h__
