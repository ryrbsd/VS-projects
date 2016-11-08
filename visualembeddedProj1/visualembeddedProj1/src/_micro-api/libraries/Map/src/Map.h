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

const int defaultArraySize = 20;

template <typename Key, typename Value>
Map<Key, Value>::Map()
{
	keys = new Key[defaultArraySize];
	values = new Value[defaultArraySize];
	size = defaultArraySize;
	for (int i = 0; i < size; i++)
	{
		keys[i] = 0;
		values[i] = 0;
	}
};

template <typename Key, typename Value>
Map<Key, Value>::~Map()
{
	delete[] keys;
	delete[] values;
}

template <typename Key, typename Value>
void Map< Key, Value>::add(Key key, Value value)
{
	for (int i = 0; i < size; i++)
	{
		if (keys[i] == 0 || keys[i] == key)
		{
			keys[i] = key;
			values[i] = value;
			if (i >= size / 2)
			{
				while (!resize());
			}
			return;
		}
	}

}

template <typename Key, typename Value>
Value Map< Key, Value>::find(Key key)
{
	for (int i = 0; i < size; i++)
	{
		if (keys[i] == key) {
			return values[i];
		}
	}
	return 0;
}

template <typename Key, typename Value>
bool Map< Key, Value>::resize()
{
	Key* tempKeys = new Key[size * 2];
	Value* tempValues = new Value[size * 2];
	if (tempKeys && tempValues)
	{
		//for (int i = 0; i < size; i++)
		//{
		//	tempKeys[i] = keys[i];
		//	tempValues[i] = values[i];
		//}

		memcpy(tempKeys, keys, size * sizeof(Key));
		memcpy(tempValues, values, size * sizeof(Value));
		delete[] keys;
		delete[] values;
		keys = tempKeys;
		values = tempValues;
		size *= 2;
		return true;
	}
	return false;


}


#endif

