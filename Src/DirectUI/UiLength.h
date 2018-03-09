#ifndef UiLength_h__
#define UiLength_h__

#include <limits>
#include <d2d1.h>

class UiLength {
public:
	UiLength() 
		:value(std::numeric_limits<double>::quiet_NaN()){

	}
	UiLength(double val)
		:value(val) {

	}
	double value;

	void SetUndefined() {
		value = std::numeric_limits<double>::quiet_NaN();
	}

	bool IsUndefined() const{
		return std::numeric_limits<double>::quiet_NaN() == value;
	}

	bool operator ==(const UiLength& other) const {return value == other.value;}
	bool operator !=(const UiLength& other) const {return value != other.value;}
	bool operator >(const UiLength& other) const {return value  > other.value;}
	bool operator <(const UiLength& other) const {return value < other.value;}
	bool operator >=(const UiLength& other) const { return value  >= other.value; }
	bool operator <=(const UiLength& other) const { return value <= other.value; }

	bool operator ==(double other) const { return value == other; }
	bool operator !=(double other) const { return value != other; }
	bool operator >(double other) const { return value > other; }
	bool operator >=(double other) const { return value >= other; }
	bool operator <(double other) const { return value < other; }
	bool operator <=(double other) const { return value <= other; }


	bool operator ==(float other) const { return value == (double)other; }
	bool operator !=(float other) const { return value != (double)other; }
	bool operator >(float other) const { return value > (double)other; }
	bool operator >=(float other) const { return value >= (double)other; }
	bool operator <(float other) const { return value < (double)other; }
	bool operator <=(float other) const { return value <= (double)other; }

	UiLength& operator +=(float other) { value += other; return *this; }
	UiLength& operator -=(float other) { value -= other; return *this; }
	UiLength& operator *=(float other) { value *= other; return *this; }
	UiLength& operator /=(float other) { value /= other; return *this; }

	UiLength& operator +=(UiLength other) { value += other.value; return *this; }
	UiLength& operator -=(UiLength other) { value -= other.value; return *this; }
	UiLength& operator *=(UiLength other) { value *= other.value; return *this; }
	UiLength& operator /=(UiLength other) { value /= other.value; return *this; }


	UiLength operator +(UiLength other) { return UiLength(value + other.value); }
	UiLength operator -(UiLength other) { return UiLength(value - other.value); }
	UiLength operator *(UiLength other) { return UiLength(value * other.value); }
	UiLength operator /(UiLength other) { return UiLength(value / other.value); }

	UiLength operator +(double other) {return UiLength(value + other); }
	UiLength operator -(double other) {return UiLength(value - other); }
	UiLength operator *(double other) {return UiLength(value * other); }
	UiLength operator /(double other) {return UiLength(value / other); }

	/*bool operator ==(FLOAT other) { return value == (double)other; }
	bool operator !=(FLOAT other) { return value != (double)other; }
	bool operator >(FLOAT other) { return value > (double)other; }
	bool operator <(FLOAT other) { return value < (double)other; }
	bool operator >=(FLOAT other) { return value >= (double)other; }
	bool operator <=(FLOAT other) { return value <= (double)other; }*/

	UiLength& operator=(double val) {
		value = val;
		return *this;
	}

	UiLength& operator=(float val) {
		value = (double)val;
		return *this;
	}

	static UiLength Undefined() {
		return UiLength(std::numeric_limits<double>::quiet_NaN());
	}
};
#endif // UiLength_h__
