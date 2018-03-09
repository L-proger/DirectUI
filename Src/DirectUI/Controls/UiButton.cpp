#include "UiButton.h"
#include <memory>
#include "../UiInputManager.h"

UiButton::UiButton(UiRendererPtr renderer, const UiString& name)
	:UiPanel(renderer, name), _isPressed(false)
{
	size = UiSize(100, 34);
	normalBackground = UiSolidColorBrush::Create(renderer, UiColor(0.7f, 0.7f, 0.7f, 1.0f));
	hoverBackground = UiSolidColorBrush::Create(renderer, UiColor(0.85f, 0.85f, 0.85f, 1.0f));
	pressedBackground = UiSolidColorBrush::Create(renderer, UiColor(0.55f, 0.55f, 0.85f, 1.0f));
	backgroundBrush = normalBackground;
}
void UiButton::OnMessage(std::shared_ptr<UiMessage> message) {
	auto inputMessage = std::dynamic_pointer_cast<UiInputMessage>(message);
	if (inputMessage != nullptr) {
		auto localCursor = ToLocalSpace(UiInputManager::mouseCoord);

		bool cursorInside = IntersectAxisAlignedRect(localCursor, GetLocalSpaceRect());

		if (inputMessage->type == UiInputMessageType::MouseMove) {
			if (cursorInside && !_isPressed) {
				backgroundBrush = hoverBackground;
			}
		}

		if (inputMessage->type == UiInputMessageType::MouseButtonDown) {
			if (inputMessage->param == 0 && cursorInside) {
				_isPressed = true;
				backgroundBrush = pressedBackground;
				return;
			}
		}
		else if (inputMessage->type == UiInputMessageType::MouseButtonUp) {
			if (inputMessage->param == 0 && cursorInside) {
				if (_isPressed) {
					Click(std::static_pointer_cast<UiButton>(shared_from_this()));
					backgroundBrush = hoverBackground;
					_isPressed = false;
				}
				return;
			}
		}
	}

	UiPanel::OnMessage(message);
}

void UiButton::OnMessagePreview(std::shared_ptr<UiMessage> message) {
	auto inputMessage = std::dynamic_pointer_cast<UiInputMessage>(message);
	if (inputMessage != nullptr) {
		auto localCursor = this->ToLocalSpace(UiInputManager::mouseCoord);

		if (inputMessage->type == UiInputMessageType::MouseMove) {
			if (!IntersectAxisAlignedRect(localCursor, GetLocalSpaceRect())) {
				_isPressed = false;
				backgroundBrush = normalBackground;
			}
		}
	}
}
void UiButton::Update(double dt) {
	UiPanel::Update(dt);
}
void UiButton::Render(UiRendererPtr renderer) {
	UiPanel::Render(renderer);
}