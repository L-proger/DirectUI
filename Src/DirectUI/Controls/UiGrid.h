#ifndef UiGrid_h__
#define UiGrid_h__

#include "../UiControl.h"
#include "../UiColumnDefinition.h"
#include "../UiRowDefinition.h"

#include <vector>

class UiGrid : public UiControl {
public:
	std::vector<UiColumnDefinition> ColumnDefinitions;
	std::vector<UiRowDefinition> RowDefinitions;
};
#endif // UiGrid_h__
