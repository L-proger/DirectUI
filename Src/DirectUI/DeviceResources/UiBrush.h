#ifndef UiBrush_h__
#define UiBrush_h__

#include "../UiTypes.h"
#include <d2d1.h>
#include "UiDeviceResource.h"

class UiBrush : public UiDeviceResource {
public:
	ID2D1BrushPtr GetBrush() {
		return _brush;
	}
protected:
	ID2D1BrushPtr _brush;
};
#endif // UiBrush_h__
