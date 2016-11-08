// Treemap.h

#ifndef _TREEMAP_h
#define _TREEMAP_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Map.h"
#include "BST.h"
template <typename Key, typename Value>
class Treemap : public Map<Key,Value> {
public:
	BST<Key, Value> *bst;

	Treemap()
	{
		bst = new BST<Key, Value>();
	}
	~Treemap()
	{
		delete bst;
	}
	int size()
	{
		return bst->size;
	}
	void add(Key key, Value value)
	{
		//Serial.println(key);
		bst->insert(key, value);
	}
	void deleteByKey(Key key)
	{
		bst->deleteNode(key);
	}
	Value find(Key key)
	{
		return bst->get(key);
	}

};



#endif

