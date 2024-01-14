/*===================================================================================
インベントリ（inventory.cpp)
Date:2024/1/15
制作者：譚偉進
====================================================================================*/
#pragma once
#include "item.h"
class Inventory {
private:
	std::list<Item> _items;
public:
	~Inventory() {

	} 
	void AddItem(Item item) { _items.push_back(item); }
	const int CountItem(ITEM_TYPE type){
		int count = 0;
		auto it = _items.begin();
		while (it != _items.end()) {
			it = std::find_if(it, _items.end(), [type](const Item item) {return item.GetItemType() == type; });
			if (it != _items.end()) {
				++count;
				++it;
			}
			else {
				break;
			}
		}
		return count;
	}
	float GetTotalWeight() {
		float total = 0.0;
		for (auto p : _items) {
			total += p.GetWeight();
		}
		return total;
	}
	void UseItem(ITEM_TYPE type) {
		for (auto it = _items.begin(); it != _items.end();) {
			if ((*it).GetItemType() == type) {
				it = _items.erase(it);
				return;
			}
			else {
				++it;
			}
		}
	}
};
