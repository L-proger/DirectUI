#include "UiZoomPan.h"


std::shared_ptr<UiZoomPan> UiZoomPan::Create(UiRendererPtr renderer, const UiString& name) {
	auto result = std::shared_ptr<UiZoomPan>(new UiZoomPan(renderer, name));
	result->contentPresenter->SetParent(result);
	return result;
}

UiZoomPan::UiZoomPan(UiRendererPtr renderer, const UiString& name)
	:UiPanel(renderer, name), _isPanning(false){
	clipContent = true;
	contentPresenter = UiPanel::Create(renderer, TEXT("ZoomPan content panel"));
}

void UiZoomPan::OnMessage(std::shared_ptr<UiMessage> message) {
	auto inputMessage = std::dynamic_pointer_cast<UiInputMessage>(message);
	auto localMouse = ToLocalSpace(UiInputManager::mouseCoord);
	bool mouseInside = IntersectAxisAlignedRect(localMouse, GetLocalSpaceRect());

	if (inputMessage != nullptr) {
		switch (inputMessage->type) {
		case UiInputMessageType::MouseMove: {
			if (mouseInside && _isPanning) {
				auto mouse = UiInputManager::mouseCoord;
				auto localStart = ToLocalSpace(contentPresenter->ToWorldSpace(_startPanPosition));
				auto diff = localMouse - localStart;
				contentPresenter->GetTransform().position += diff;
				return;
			}
		}
		break;
		case UiInputMessageType::MouseVWheel: {
			float zoomPower = 1.1f;
			auto mouse = UiInputManager::mouseCoord;
			auto m0 = contentPresenter->ToLocalSpace(mouse);
			auto m2 = ToLocalSpace(mouse);
			contentPresenter->GetTransform().scale *= inputMessage->param > 0 ? zoomPower : (1.0f / zoomPower);
			auto m1 = contentPresenter->ToWorldSpace(m0);
			contentPresenter->GetTransform().position -= ToLocalSpace(m1) - m2;
			return;
		}
		break;
		case UiInputMessageType::MouseButtonUp:
			if (mouseInside) {
				if (inputMessage->param == 1) {
					contentPresenter->GetTransform().scale = 1.0;
					contentPresenter->GetTransform().position = UiPoint(0, 0);
				}
			}
			if (_isPanning && inputMessage->param == 0) {
				_isPanning = false;
				GetCoreWindow()->UnlockInput();
			}
			return;
			break;
		case UiInputMessageType::MouseButtonDown:
			if (inputMessage->param == 0 && mouseInside) {
				GetCoreWindow()->LockInput();
				_isPanning = true;
				_startPanPosition = contentPresenter->ToLocalSpace(UiInputManager::mouseCoord);
				return;
			}
			break;
		default:
			break;
		}
	}
	UiPanel::OnMessage(message);
}

void UiZoomPan::Update(double dt) {
	contentPresenter->size = size;
	UiPanel::Update(dt);
}

void UiZoomPan::ArrangeChildren(UiRect constraint) {

}