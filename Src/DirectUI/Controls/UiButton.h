#ifndef UiButton_h__
#define UiButton_h__

#include "UiPanel.h"
#include "../Event.h"
#include "UiLabel.h"
#include <memory>

class UiButton : public UiPanel {
public:
	typedef Event<std::shared_ptr<UiButton>> button_event_t;
	button_event_t Click;
	static std::shared_ptr<UiButton> Create(UiRendererPtr renderer, const UiString& name) {
		return std::shared_ptr<UiButton>(new UiButton(renderer, name));
	}
	static std::shared_ptr<UiButton> Create(UiRendererPtr renderer, const UiString& name, const UiString& text) {
		auto result = std::shared_ptr<UiButton>(new UiButton(renderer, name));
		auto label = UiLabel::Create(renderer, L"txt");
		label->text = text;
		label->SetParent(result);
		return result;
	}
private:  
	UiBrushPtr normalBackground;
	UiBrushPtr hoverBackground;
	UiBrushPtr pressedBackground;

	bool _isPressed;
	UiButton(UiRendererPtr renderer, const UiString& name);
	virtual void OnMessage(std::shared_ptr<UiMessage> message) override;
	virtual void OnMessagePreview(std::shared_ptr<UiMessage> message) override;
	virtual void Update(double dt) override;
	virtual void Render(UiRendererPtr renderer) override;
};
#endif // UiButton_h__
