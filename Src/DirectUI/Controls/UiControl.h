#ifndef UiControl_h__
#define UiControl_h__

#include "UiTransform.h"
#include <memory>
#include <string>
#include "../UiRenderer.h"
#include "../UiCore.h"
#include "../UiMessage.h"
#include "../UiProperties.h"
#include "../UiInputMessage.h"
#include "../Event.h"
#include "../UiAlignment.h"
#include "../UiRect.h"

class UiControl : public std::enable_shared_from_this<UiControl> {
public:
	typedef Event<UiControlPtr> control_event_t;
	control_event_t DesiredSizeChanged;
	UiVerticalAlignment verticalAlignment = UiVerticalAlignment::Stretch;
	UiHorizontalAlignment horizontalAlignment = UiHorizontalAlignment::Stretch;

	uint32_t GridColumn;
	uint32_t GridRow;
	UiSize size;
	bool clipContent = false;
	UiControl(const UiString& name);
	D2D1_RECT_F GetLocalSpaceRect();
	static bool IntersectAxisAlignedRect(const UiPoint& point, D2D1_RECT_F& rect);
	UiPoint ToLocalSpace(UiPoint worldPoint);
	UiPoint ToWorldSpace(UiPoint localPoint);
	void PushMessage(std::shared_ptr<UiMessage> message);

	virtual void OnMessagePreview(std::shared_ptr<UiMessage> message);
	virtual void OnMessage(std::shared_ptr<UiMessage> message);
	virtual ~UiControl();
	virtual UiCoreWindowPtr GetCoreWindow();
	virtual void Render(UiRendererPtr renderer);
	virtual void Update(double dt);
	void ApplyTransform(UiRendererPtr renderer);
	void SetParent(UiControlPtr parent);
	UiTransform& GetTransform();
	void Measure(UiSize availableSize);
	void Arrange(UiRect localSpaceConstraint);

	UiSize DesiredSize();
	const std::vector<UiControlPtr> GetChildren();
protected:
	virtual UiSize MeasureInternal(UiSize availableSize);
	virtual UiRect ArrangeInternal(UiRect constraint);
	virtual void ArrangeChildren(UiRect constraint);
private:
	UiSize _desiredSize;
	void OnMessagePreviewInternal(std::shared_ptr<UiMessage> message);
	UiTransform transform;
	UiString _name;
};

#endif // UiControl_h__
