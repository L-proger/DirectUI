#ifndef UiValueProperty_h__
#define UiValueProperty_h__

#include "UiAttachedProperty.h"
#include "UiGridLength.h"

template<typename T>
class UiValueProperty : public UiAttachedProperty {
public:
	UiValueProperty(const UiString& name, const T& value)
		: UiAttachedProperty(name), _value(value) {

	}
private:
	T _value;
};
#endif // UiValueProperty_h__
