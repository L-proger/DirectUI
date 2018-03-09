#ifndef UiAttachedProperty_h__
#define UiAttachedProperty_h__

#include <string>
#include "UiTypes.h"

class UiAttachedProperty {
public:
	UiAttachedProperty(const UiString& name) : _name(name) {

	}
protected:
	UiString _name;
};
#endif // UiAttachedProperty_h__
