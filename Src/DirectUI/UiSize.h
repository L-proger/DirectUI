#ifndef UiSize_h__
#define UiSize_h__

#include "UiLength.h"

class UiSize {
public:
	UiLength Width;
	UiLength Height;

	UiSize() {

	}

	UiSize(UiLength width, UiLength height) 
		:Width(width), Height(height)
	{

	}

	void SetUndefined() {
		Width.SetUndefined();
		Height.SetUndefined();
	}
};
#endif // UiSize_h__
