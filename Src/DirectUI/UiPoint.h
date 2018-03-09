#ifndef UiPoint_h__
#define UiPoint_h__

#include "UiLength.h"

class UiPoint {
public:
	UiLength x;
	UiLength y;

	UiPoint(UiLength _x, UiLength _y)
		:x(_x), y(_y)
	{

	}

	UiPoint()
		:x(0), y(0)
	{

	}

	UiPoint& operator =(double other) {
		x = other;
		y = other;
		return *this;
	}


	bool operator ==(const UiPoint& other) const{
		return (x == other.x) && (y == other.y);
	}

	UiPoint operator -(const UiPoint other) {
		return UiPoint(x - other.x, y - other.y);
	}

	UiPoint operator +(const UiPoint other) {
		return UiPoint(x + other.x, y + other.y);
	}

	UiPoint& operator +=(UiPoint other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	UiPoint& operator -=(UiPoint other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	UiPoint& operator *=(UiPoint other) {
		x *= other.x;
		y *= other.y;
		return *this;
	}
	UiPoint& operator /=(UiPoint other) {
		x /= other.x;
		y /= other.y;
		return *this;
	}

	UiPoint& operator /=(UiLength other) {
		x /= other;
		y /= other;
		return *this;
	}

	UiPoint& operator *=(UiLength other) {
		x *= other;
		y *= other;
		return *this;
	}
	void SetUndefined() {
		x.SetUndefined();
		y.SetUndefined();
	}
};

#endif // UiPoint_h__
