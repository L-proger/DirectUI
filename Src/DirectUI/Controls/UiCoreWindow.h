#ifndef UiCoreWindow_h__
#define UiCoreWindow_h__


#include "UiControl.h"
#include <cstdint>
#include <memory>
#include <functional>
#include "../UiInputMessage.h"
#include "../UiInputManager.h"

class UiCoreWindow : public UiControl {
public:
	virtual void Update(double dt) override;
	virtual UiCoreWindowPtr GetCoreWindow() override;
	virtual void LockInput();
	virtual void UnlockInput();
	virtual UiRendererPtr GetRenderer() = 0;
protected:
	UiCoreWindow(const UiString& name);
private:
	UiCorePtr _uiCore;
};

#endif // UiCoreWindow_h__
