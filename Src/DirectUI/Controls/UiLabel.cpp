#include "UiLabel.h"

void UiLabel::Render(UiRendererPtr renderer) {
	if (foregroundBrush != nullptr) {
		ApplyTransform(renderer);
		renderer->GetRenderTarget()->DrawText(text.c_str(), (UINT32)text.size(), _format.Get(), D2D1::RectF(0, 0, (float)size.Width.value, (float)size.Height.value), foregroundBrush->GetBrush().Get());
		UiControl::Render(renderer);
	}
}

std::shared_ptr<UiLabel> UiLabel::Create(UiRendererPtr renderer, const UiString& name) {
	return std::shared_ptr<UiLabel>(new UiLabel(renderer, name));
}
void UiLabel::SetFontSize(float fontSize) {
	_fontSize = fontSize;
	RebuildTextFormat();
}

UiLabel::UiLabel(UiRendererPtr renderer, const UiString& name) : UiControl(name), text(L"Label") {
	size = UiSize(128, 24);
	_dwFactory = renderer->GetWriteFactory();
	_fontName = TEXT("Verdana");
	_fontSize = 14.0f;
	RebuildTextFormat();
	foregroundBrush = UiSolidColorBrush::Black(renderer);
}

void UiLabel::RebuildTextFormat() {
	_format = nullptr;
	auto hr = _dwFactory->CreateTextFormat(
		_fontName.c_str(),
		NULL,
		DWRITE_FONT_WEIGHT_NORMAL,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		_fontSize,
		L"", //locale
		&_format
		);
}

UiSize UiLabel::MeasureInternal(UiSize availableSize) {
	
	ComPtr<IDWriteTextLayout> layout;
	_dwFactory->CreateTextLayout(text.c_str(), (UINT32)text.size(), _format.Get(), (float)size.Width.value, (float)size.Height.value, &layout);
	
	DWRITE_TEXT_METRICS tm;
	layout->GetMetrics(&tm);
	
	return UiSize(tm.width, tm.height);
}