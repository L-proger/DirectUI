#include <windows.h>
#include <DirectUI/Ui.h>
#include <DirectUI/Controls/UiHwndCoreWindow.h>

#pragma comment(lib, "DirectUI.lib")

std::shared_ptr<UiHwndCoreWindow> wnd0;
std::shared_ptr<UiHwndCoreWindow> wnd1;
void OnClickWnd1(std::shared_ptr<UiButton> button);

void OnClickWnd0(std::shared_ptr<UiButton> button) {
	button->Click -= OnClickWnd0;
	button->Click += OnClickWnd1;
	button->SetParent(wnd1);
}

void OnClickWnd1(std::shared_ptr<UiButton> button) {
	button->Click -= OnClickWnd1;
	button->Click += OnClickWnd0;
	button->SetParent(wnd0);
}

int main() {
	wnd0 = UiHwndCoreWindow::Create(L"Win0");
	wnd1 = UiHwndCoreWindow::Create(L"Win1");


	auto button = UiButton::Create(wnd0->GetRenderer(), L"Btn0", L"Test button");
	button->horizontalAlignment = UiHorizontalAlignment::Left;
	button->verticalAlignment = UiVerticalAlignment::Top;
	button->SetParent(wnd0);

	button->Click += OnClickWnd0;

	while (true) {
		wnd0->Update(1);
		wnd1->Update(1);
		wnd0->Render();
		wnd1->Render();
	}

	return 0;
}

