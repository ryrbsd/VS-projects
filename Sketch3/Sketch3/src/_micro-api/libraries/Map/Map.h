// Map.h

#ifndef _MAP_h
#define _MAP_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
template <typename Key, typename Value> class Map
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

