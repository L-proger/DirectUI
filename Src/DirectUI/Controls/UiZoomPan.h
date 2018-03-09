#ifndef UiZoomPan_h__
#define UiZoomPan_h__

#include "UiPanel.h"
#include <memory>
#include "../UiInputManager.h"
#include "UiCoreWindow.h"

class UiZoomPan : public UiPanel {
public:
	static std::shared_ptr<UiZoomPan> Create(UiRendererPtr renderer, const UiString& name);
	std::shared_ptr<UiPanel> contentPresenter;
protected:
	bool _isPanning;
	UiPoint _startPanPosition;
	UiZoomPan(UiRendererPtr renderer, const UiString& name);
	virtual void OnMessage(std::shared_ptr<UiMessage> message) override;
	virtual void Update(double dt) override;
	virtual void ArrangeChildren(UiRect constraint) override;
};
#endif // UiZoomPan_h__
