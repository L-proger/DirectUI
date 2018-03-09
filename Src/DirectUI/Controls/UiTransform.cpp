#include "UiTransform.h"
#include "UiControl.h"

void UiTransform::Draw() {
	for (auto child : _children) {
		child->GetTransform().Draw();
	}
}

D2D1::Matrix3x2F UiTransform::LocalToWorldMatrix() {
	auto m = D2D1::Matrix3x2F::Scale((float)scale.x.value, (float)scale.y.value) *
		D2D1::Matrix3x2F::Rotation(rotation) *
		D2D1::Matrix3x2F::Translation((float)position.x.value, (float)position.y.value);
	auto p = _parent.lock();
	if (p != nullptr) {
		return m * p->GetTransform().LocalToWorldMatrix();
	}
	return m;
}

D2D1::Matrix3x2F UiTransform::WorldToLocalMatrix() {
	auto m = LocalToWorldMatrix();
	m.Invert();
	return m;
}

const UiTransform::children_container UiTransform::GetChildren() const {
	return _children;
}

UiControlPtr UiTransform::GetParent() const {
	return _parent.lock();
}

std::weak_ptr<UiControl> UiTransform::GetControl() const {
	return _control;
}


void UiTransform::SetParent(UiControlPtr parent) {
	auto localParent = _parent.lock();
	if (parent == localParent) {
		return;
	}

	if (localParent != nullptr) {
		localParent->GetTransform()._children.erase(
			std::remove_if(localParent->GetTransform()._children.begin(), localParent->GetTransform()._children.end(),
				[this](UiControlPtr ptr) {return ptr == this->_control.lock(); }),
			std::end(localParent->GetTransform()._children));
	}

	_parent = parent;
	localParent = _parent.lock();
	if (localParent != nullptr) {
		localParent->GetTransform()._children.push_back(_control.lock());
	}
}
UiTransform::UiTransform()
	: position(0, 0), rotation(0.0f), scale(1, 1) {

}