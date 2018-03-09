#ifndef Ui_Types_h__
#define Ui_Types_h__

#include <memory>
#include <string>
#include "UiD2d.h"
#include "UiSize.h"
#include "UiPoint.h"

class UiTransform;
typedef std::shared_ptr<UiTransform> UiTransformPtr;

class UiControl;
typedef std::shared_ptr<UiControl> UiControlPtr;

class Window;
typedef std::shared_ptr<Window> WindowPtr;

class UiBitmap;
typedef std::shared_ptr<UiBitmap> UiBitmapPtr;

class UiBrush;
typedef std::shared_ptr<UiBrush> UiBrushPtr;

class Window;
typedef std::shared_ptr<Window> WindowPtr;

class UiCoreWindow;
typedef std::shared_ptr<UiCoreWindow> UiCoreWindowPtr;

class UiRenderer;
typedef std::shared_ptr<UiRenderer> UiRendererPtr;

typedef std::wstring UiString;

class UiCore;
typedef std::shared_ptr<UiCore> UiCorePtr;



#endif // Ui_Types_h__
