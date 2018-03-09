#ifndef UiGridLength_h__
#define UiGridLength_h__

enum class UiGridUnitType {
	Auto,
	Pixel, 
	Star
};

class UiGridLength {
public:
	UiGridLength(double value):_value(value), _unitType(UiGridUnitType::Pixel){}
	UiGridLength(double value, UiGridUnitType type) :_value(value), _unitType(type) {}

	UiGridUnitType GridUnitType() {
		return _unitType;
	}

	bool IsAbsolute() {
		return _unitType == UiGridUnitType::Pixel;
	}
	bool IsAuto() {
		return _unitType == UiGridUnitType::Auto;
	}
	bool IsStar() {
		return _unitType == UiGridUnitType::Star;
	}
	double Value() {
		return _value;
	}
	static UiGridLength Auto() {
		return UiGridLength(0, UiGridUnitType::Auto);
	}
private:
	UiGridUnitType _unitType;
	double _value;
};
#endif // UiGridLength_h__
