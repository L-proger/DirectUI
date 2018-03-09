#ifndef UiRect_h__
#define UiRect_h__
#include "UiPoint.h"
#include "UiSize.h"

class UiRect {
public:
	UiLength x;
	UiLength y;
	UiLength width;
	UiLength height;

	UiRect() 
		:x(0), y(0), width(0), height(0)
	{

	}

	UiRect(UiLength _x, UiLength _y, UiLength _width, UiLength _height)
		:x(_x), y(_y), width(_width), height(_height)
	{

	}

	UiPoint TopLeft() {
		return UiPoint(x, y);
	}

	UiSize Size() {
		return UiSize(width, height);
	}
};
#endif // UiRect_h__
