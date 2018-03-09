#ifndef UiLabel_h__
#define UiLabel_h__

#include "UiControl.h"
#include <string>
#include <dwrite.h>
#include <memory>

#include "../UiCore.h"
#include "../DeviceResources/UiSolidColorBrush.h"

class UiLabel : public UiControl {
public:
	std::wstring text;
	UiBrushPtr foregroundBrush;
	virtual void Render(UiRendererPtr renderer) override;
	static std::shared_ptr<UiLabel> Create(UiRendererPtr renderer, const UiString& name);
	void SetFontSize(float fontSize);
	~UiLabel() {
		printf("UiLabel destructor\n");
	}
protected:
	UiLabel(UiRendererPtr renderer, const UiString& name);
	virtual UiSize MeasureInternal(UiSize availableSize) override;
private:
	std::wstring _fontName;
	float _fontSize;
	IDWriteFactoryPtr _dwFactory;
	IDWriteTextFormatPtr _format;
	void RebuildTextFormat();
};
#endif // UiLabel_h__
