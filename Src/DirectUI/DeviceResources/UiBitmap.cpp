#include "UiBitmap.h"

ID2D1BitmapPtr UiBitmap::GetBitmap() {
	return _bitmap;
}

std::shared_ptr<UiBitmap> UiBitmap::Create(UiRendererPtr renderer, uint32_t width, uint32_t height, D2D1_PIXEL_FORMAT format) {
	return std::shared_ptr<UiBitmap>(new UiBitmap(renderer, width, height, format));
}

UiBitmap::UiBitmap(UiRendererPtr renderer, uint32_t width, uint32_t height, D2D1_PIXEL_FORMAT format) {
	D2D1_SIZE_U size;
	size.width = width;
	size.height = height;

	D2D1_BITMAP_PROPERTIES props;
	props.dpiX = 96;
	props.dpiY = 96;
	props.pixelFormat = format;
	renderer->GetRenderTarget()->CreateBitmap(size, props, &_bitmap);
}
UiBitmap::UiBitmap(ID2D1BitmapPtr bitmap) 
	:_bitmap(bitmap){

}
std::shared_ptr<UiBitmap> UiBitmap::Create(ID2D1BitmapPtr bitmap) {
	return std::shared_ptr<UiBitmap>(new UiBitmap(bitmap));
}