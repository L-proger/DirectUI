#ifndef UiHwndRenderer_h__
#define UiHwndRenderer_h__

#include "../UiRenderer.h"
#include <memory>

class UiHwndRenderer : public UiRenderer {
public:
	void Init(WindowPtr window);
	static std::shared_ptr<UiHwndRenderer> Create();
private:
	UiHwndRenderer() {

	}
};
#endif // UiHwndRenderer_h__
