#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item {
protected:
	std::string name;

public:
	Item(const std::string& name) : name(name) {}
	virtual ~Item() {}
	virtual void use() = 0;

	std::string getName() const { return name; }
};

#endif