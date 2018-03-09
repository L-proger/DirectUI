#include "UiBitmapBrush.h"

std::shared_ptr<UiBitmapBrush> UiBitmapBrush::Create(UiRendererPtr renderer, UiBitmapPtr bitmap) {
	return std::shared_ptr<UiBitmapBrush>(new UiBitmapBrush(renderer, bitmap));
}

UiBitmapBrush::UiBitmapBrush(UiRendererPtr renderer, UiBitmapPtr bitmap) {
	_bitmap = bitmap;
	renderer->GetRenderTarget()->CreateBitmapBrush(bitmap->GetBitmap().Get(), &_bitmapBrush);
	_brush = _bitmapBrush;
	_bitmapBrush->SetInterpolationMode(D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
}