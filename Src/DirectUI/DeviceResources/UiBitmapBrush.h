#ifndef UiBitmapBrush_h__
#define UiBitmapBrush_h__

#include "UiBrush.h"
#include "../UiRenderer.h"
#include <d2d1.h>
#include "../UiTypes.h"
#include "UiBitmap.h"
#include <memory>

class UiBitmapBrush : public UiBrush {
public:
	static std::shared_ptr<UiBitmapBrush> Create(UiRendererPtr renderer, UiBitmapPtr bitmap);
	ID2D1BitmapBrushPtr GetNativeBitmapBrush() {
		return _bitmapBrush;
	}
	UiBitmapPtr GetBitmap() {
		return _bitmap;
	}
protected:
	UiBitmapBrush(UiRendererPtr renderer, UiBitmapPtr bitmap);

private:
	ID2D1BitmapBrushPtr _bitmapBrush;
	UiBitmapPtr _bitmap;
};
#endif // UiBitmapBrush_h__
