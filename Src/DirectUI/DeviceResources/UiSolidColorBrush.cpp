#include "UiSolidColorBrush.h"

UiColor UiSolidColorBrush::GetColor() {
	auto color = _colorBrush->GetColor();
	return UiColor(color.r, color.g, color.b, color.a);
}
void UiSolidColorBrush::SetColor(const UiColor& color) {
	D2D1_COLOR_F c;
	c.r = color.r;
	c.g = color.g;
	c.b = color.b;
	c.a = color.a;
	_colorBrush->SetColor(c);
}
std::shared_ptr<UiSolidColorBrush> UiSolidColorBrush::Red(UiRendererPtr renderer) {
	return UiSolidColorBrush::Create(renderer, UiColor(1, 0, 0, 1));
}
std::shared_ptr<UiSolidColorBrush> UiSolidColorBrush::Green(UiRendererPtr renderer) {
	return UiSolidColorBrush::Create(renderer, UiColor(0, 1, 0, 1));
}
std::shared_ptr<UiSolidColorBrush> UiSolidColorBrush::Blue(UiRendererPtr renderer) {
	return UiSolidColorBrush::Create(renderer, UiColor(0, 0, 1, 1));
}
std::shared_ptr<UiSolidColorBrush> UiSolidColorBrush::Black(UiRendererPtr renderer) {
	return UiSolidColorBrush::Create(renderer, UiColor(0, 0, 0, 1));
}
std::shared_ptr<UiSolidColorBrush> UiSolidColorBrush::White(UiRendererPtr renderer) {
	return UiSolidColorBrush::Create(renderer, UiColor(1, 1, 1, 1));
}

std::shared_ptr<UiSolidColorBrush> UiSolidColorBrush::Create(UiRendererPtr renderer, const UiColor& color) {
	return std::shared_ptr<UiSolidColorBrush>(new UiSolidColorBrush(renderer, color));
}

UiSolidColorBrush::UiSolidColorBrush(UiRendererPtr renderer, const UiColor& color) {
	SetRenderTarget(renderer->GetRenderTarget());
	SetColor(color);
}

void UiSolidColorBrush::SetRenderTarget(ID2D1RenderTargetPtr newOwner) {
	/*if (_owner == newOwner) {
		return;
	}
	_owner = newOwner;
	*/
	D2D1_COLOR_F color = { 0 };
	if (_colorBrush != nullptr) {
		color = _colorBrush->GetColor();
	}

	if (newOwner != nullptr) {
		newOwner->CreateSolidColorBrush(color, &_colorBrush);
		_brush = _colorBrush;
	}
}