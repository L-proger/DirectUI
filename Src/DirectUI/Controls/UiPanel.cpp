#include "UiPanel.h"

void UiPanel::Render(UiRendererPtr renderer) {
	if (backgroundBrush != nullptr) {
		renderer->GetRenderTarget()->SetTransform(GetTransform().LocalToWorldMatrix());
		D2D1_RECT_F rect = D2D1::RectF(0, 0, (float)size.Width.value, (float)size.Height.value);
		renderer->GetRenderTarget()->FillRectangle(&rect, backgroundBrush->GetBrush().Get());
	}
	UiControl::Render(renderer);
}

std::shared_ptr<UiPanel> UiPanel::Create(UiRendererPtr renderer, const UiString& name) {
	return std::shared_ptr<UiPanel>(new UiPanel(renderer, name));
}

UiPanel::UiPanel(UiRendererPtr renderer, const UiString& name)
	:UiControl(name) {
	size = UiSize(128, 128);
}