#ifndef UiSolidColorBrush_h__
#define UiSolidColorBrush_h__

#include "UiBrush.h"
#include "../UiRenderer.h"
#include <d2d1.h>
#include "../UiColor.h"
#include <memory>

class UiSolidColorBrush : public UiBrush{
public:
	UiColor GetColor();
	void SetColor(const UiColor& color);
	static std::shared_ptr<UiSolidColorBrush> Red(UiRendererPtr renderer);
	static std::shared_ptr<UiSolidColorBrush> Green(UiRendererPtr renderer);
	static std::shared_ptr<UiSolidColorBrush> Blue(UiRendererPtr renderer);
	static std::shared_ptr<UiSolidColorBrush> Black(UiRendererPtr renderer);
	static std::shared_ptr<UiSolidColorBrush> White(UiRendererPtr renderer);
	static std::shared_ptr<UiSolidColorBrush> Create(UiRendererPtr renderer, const UiColor& color);
	void SetRenderTarget(ID2D1RenderTargetPtr newOwner);
protected:
	UiSolidColorBrush(UiRendererPtr renderer, const UiColor& color);
private:
	ID2D1SolidColorBrushPtr _colorBrush;
};
#endif // UiSolidColorBrush_h__
