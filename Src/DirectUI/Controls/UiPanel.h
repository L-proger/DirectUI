#ifndef Panel_h__
#define Panel_h__

#include "UiControl.h"
#include "../DeviceResources/UiSolidColorBrush.h"

class UiPanel : public UiControl {
public:
	std::shared_ptr<UiBrush> backgroundBrush;
	virtual void Render(UiRendererPtr renderer) override;
	static std::shared_ptr<UiPanel> Create(UiRendererPtr renderer, const UiString& name);
protected:
	UiPanel(UiRendererPtr renderer, const UiString& name);
};
#endif // Panel_h__
