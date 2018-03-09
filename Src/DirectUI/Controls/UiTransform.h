#ifndef RectTransform_h__
#define RectTransform_h__

#include "../UiTypes.h"
#include <d2d1.h>
#include <vector>
#include <algorithm>
#include <memory>
#include "../UiPoint.h"

class UiTransform {
public:
	friend class UiControl;
	typedef std::vector<UiControlPtr> children_container;
	UiPoint position;
	float rotation;
	UiPoint scale;
	
	virtual void Draw();
	D2D1::Matrix3x2F LocalToWorldMatrix();
	D2D1::Matrix3x2F WorldToLocalMatrix();
	const children_container GetChildren() const;
	UiControlPtr GetParent() const;
	std::weak_ptr<UiControl> GetControl() const;
	UiTransform();
protected:
	void SetParent(UiControlPtr parent);
	
private:
	std::weak_ptr<UiControl> _control;
	std::weak_ptr<UiControl> _parent;
	children_container _children;
};
#endif // RectTransform_h__
