#ifndef Map_h
#define Map_h

#include "Arduino.h"
template <class Key, class Value> class Map
{
public:
	Map();
	~Map();
	void add(Key key, Value value);
	Value find(Key key);
private:
	Key *keys;
	Value *values;
	int size;
	bool resize();
};

#endif