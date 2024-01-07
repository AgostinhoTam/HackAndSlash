#include "stdafx.h"
#include "inventory.h"

Inventory::Inventory(Item* item)
{
	_itemtype = item->GetItemType();
	_weight = item->GetWeight();
}
