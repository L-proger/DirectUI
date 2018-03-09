#include "UiCoreWindow.h"

void UiCoreWindow::Update(double dt) {
	UiControl::Measure(size);
	UiControl::Arrange(UiRect(0, 0, size.Width, size.Height));
	UiControl::Update(dt);
}

UiCoreWindowPtr UiCoreWindow::GetCoreWindow() {
	return std::static_pointer_cast<UiCoreWindow>(shared_from_this());
}

void UiCoreWindow::LockInput() {
	//SetCapture(_window->GetHwnd());
}

void UiCoreWindow::UnlockInput() {
	//ReleaseCapture();
}

UiCoreWindow::UiCoreWindow(const UiString& name)
	:UiControl(name) {

}


