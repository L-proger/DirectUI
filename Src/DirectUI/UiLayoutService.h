#ifndef UiLayoutService_h__
#define UiLayoutService_h__

#include "UiTypes.h"
#include "UiRect.h"
#include "UiControl.h"

class UiLayoutService {
public:
	static UiRect SimpleLayout(UiControlPtr control, UiRect constraint) {
		UiRect result;
		auto desiredSize = control->DesiredSize();

		if (control->horizontalAlignment == UiHorizontalAlignment::Stretch) {
			result.x = constraint.x;
			result.width = constraint.Size().Width;
		}
		else if (control->horizontalAlignment == UiHorizontalAlignment::Left) {
			result.x = constraint.x;
			result.width = desiredSize.Width;
		}
		else if (control->horizontalAlignment == UiHorizontalAlignment::Right) {
			result.x = constraint.x + (constraint.Size().Width - desiredSize.Width);
			result.width = desiredSize.Width;
		}
		else if (control->horizontalAlignment == UiHorizontalAlignment::Center) {
			result.x = constraint.x + (constraint.Size().Width - desiredSize.Width) / 2.0;
			result.width = desiredSize.Width;
		}



		if (control->verticalAlignment == UiVerticalAlignment::Stretch) {
			result.y = constraint.y;
			result.height = constraint.Size().Height;
		}
		else if (control->verticalAlignment == UiVerticalAlignment::Top) {
			result.y = constraint.y;
			result.height = desiredSize.Height;
		}
		else if (control->verticalAlignment == UiVerticalAlignment::Bottom) {
			result.y = constraint.y + (constraint.Size().Height - desiredSize.Height);
			result.height = desiredSize.Height;
		}
		else if (control->verticalAlignment == UiVerticalAlignment::Center) {
			result.y = constraint.y + (constraint.Size().Height - desiredSize.Height) / 2.0;
			result.height = desiredSize.Height;
		}

		return result;
	}
};
#endif // UiLayoutService_h__
