#ifndef UiInputMessage_h__
#define UiInputMessage_h__

#include "UiMessage.h"

enum class UiInputMessageType {
	MouseMove,
	KeyDown,
	MouseHWheel,
	MouseVWheel,
	MouseButtonUp,
	MouseButtonDown,
};

class UiInputMessage : public UiMessage{
public:
	UiInputMessageType type;
	int param;
};
#endif // UiInputMessage_h__
