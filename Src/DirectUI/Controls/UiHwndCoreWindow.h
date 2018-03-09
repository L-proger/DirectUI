#ifndef UiHwndCoreWindow_h__
#define UiHwndCoreWindow_h__

#include "UiNativeWindowBase.h"
#include "../Renderers/UiHwndRenderer.h"

class UiHwndCoreWindow : public UiNativeWindowBase {
public:
	static std::shared_ptr<UiHwndCoreWindow> Create(const UiString& name);
	UiHwndCoreWindow(const UiString& name);
	virtual UiRendererPtr GetRenderer() override;
	virtual void Update(double dt) override;
	void Render();

	virtual void LockInput() override;
	virtual void UnlockInput() override;

private:
	std::shared_ptr<UiHwndRenderer> _renderer;
};
#endif // UiHwndCoreWindow_h__
