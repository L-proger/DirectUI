#include "UiControl.h"
#include "../UiLayoutService.h"

UiControl::UiControl(const UiString& name) :_name(name), GridRow(0), GridColumn(1) {}

D2D1_RECT_F UiControl::GetLocalSpaceRect() {
	return D2D1::RectF(0, 0, (float)size.Width.value, (float)size.Height.value);
}

bool UiControl::IntersectAxisAlignedRect(const UiPoint& point, D2D1_RECT_F& rect) {
	return (point.x >= rect.left) && (point.x <= rect.right) && (point.y >= rect.top) && (point.y <= rect.bottom);
}

UiPoint UiControl::ToLocalSpace(UiPoint worldPoint) {
	auto result = GetTransform().WorldToLocalMatrix().TransformPoint(D2D1::Point2F((float)worldPoint.x.value, (float)worldPoint.y.value));
	return UiPoint(result.x, result.y);
}

UiPoint UiControl::ToWorldSpace(UiPoint localPoint) {
	auto result = GetTransform().LocalToWorldMatrix().TransformPoint(D2D1::Point2F((float)localPoint.x.value, (float)localPoint.y.value));
	return UiPoint(result.x, result.y);
}

void UiControl::PushMessage(std::shared_ptr<UiMessage> message) {
	OnMessagePreviewInternal(message);
	if (GetTransform().GetChildren().size() == 0) {
		OnMessage(message);
	}
	else {
		for (auto child : GetTransform().GetChildren()) {
			if (child != nullptr) {
				child->PushMessage(message);
			}
		}
	}
}

void UiControl::OnMessage(std::shared_ptr<UiMessage> message) {
	if (GetTransform().GetParent() != nullptr) {
		GetTransform().GetParent()->OnMessage(message);
	}
}

void UiControl::OnMessagePreview(std::shared_ptr<UiMessage> message) {

}

void UiControl::OnMessagePreviewInternal(std::shared_ptr<UiMessage> message) {
	OnMessagePreview(message);
}

UiControl::~UiControl() {

}

UiCoreWindowPtr UiControl::GetCoreWindow() {
	if (GetTransform().GetParent() != nullptr) {
		return GetTransform().GetParent()->GetCoreWindow();
	}
	return nullptr;
}

void UiControl::Render(UiRendererPtr renderer) {
	ApplyTransform(renderer);
	if (clipContent) {
		renderer->GetRenderTarget()->PushAxisAlignedClip(D2D1::RectF(0, 0, (float)size.Width.value, (float)size.Height.value), D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
	}
	for (auto child : GetTransform().GetChildren()) {
		if (child != nullptr) {
			child->Render(renderer);
		}
	}
	if (clipContent) {
		renderer->GetRenderTarget()->PopAxisAlignedClip();
	}
}

void UiControl::Update(double dt) {
	for (auto child : GetTransform().GetChildren()) {
		if (child != nullptr) {
			child->Update(dt);
		}
	}
}

void UiControl::ApplyTransform(UiRendererPtr renderer) {
	renderer->GetRenderTarget()->SetTransform(GetTransform().LocalToWorldMatrix());
}

void UiControl::SetParent(UiControlPtr parent) {
	GetTransform().SetParent(parent);
}

UiTransform& UiControl::GetTransform() {
	transform._control = shared_from_this();
	return transform;
}

UiSize UiControl::MeasureInternal(UiSize availableSize) {
	UiSize result(0,0);
	UiSize desiredContentSize(0,0);
	auto children = GetChildren();
	if (children.size() > 0) {
		desiredContentSize = children[0]->DesiredSize();
	}

	result.Width = size.Width.IsUndefined() ? desiredContentSize.Width : size.Width;
	result.Height = size.Height.IsUndefined() ? desiredContentSize.Height : size.Height;
	return result;
}

void UiControl::Measure(UiSize availableSize) {
	for (auto c : GetTransform().GetChildren()) {
		c->Measure(availableSize);
	}
	_desiredSize = MeasureInternal(availableSize);
	DesiredSizeChanged(shared_from_this());
}

UiSize UiControl::DesiredSize() {
	return _desiredSize;
}

const std::vector<UiControlPtr> UiControl::GetChildren() {
	return GetTransform().GetChildren();
}

void UiControl::ArrangeChildren(UiRect constraint) {
	for (auto c : GetChildren()) {
		c->Arrange(constraint);
	}
}

void UiControl::Arrange(UiRect localSpaceConstraint) {
	auto newRect = ArrangeInternal(localSpaceConstraint);
	transform.position = newRect.TopLeft();
	size = newRect.Size();
	ArrangeChildren(UiRect(0, 0, newRect.Size().Width, newRect.Size().Height));
}

UiRect UiControl::ArrangeInternal(UiRect constraint) {
	return UiLayoutService::SimpleLayout(shared_from_this(), constraint);
}