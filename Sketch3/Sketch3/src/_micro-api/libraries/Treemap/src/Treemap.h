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
//Tree map is a map based on BST inheritant from Map
template <typename Key, typename Value>
class Treemap : public Map<Key,Value> {
public:
	BST<Key, Value> *bst; //the bst data structure to store data.

	/*==========Treemap==============
	Constructor of Treemap
	*/
	Treemap()
	{
		bst = new BST<Key, Value>(); // create a BST to store data
	}
	/*==========~Treemap==============
	Disstructor of Treemap
	*/
	~Treemap()
	{
		delete bst;
	}
	
	/*==========size==============
	Get size of BST which is the size of Treemap
	*/
	int size()
	{
		return bst->size;
	}
	
	/*==========add==============
	Insert key value into bst, by calling built in function of bst.
	Input: Key key, Value value
	*/
	void add(Key key, Value value)
	{
		bst->insert(key, value);
	}
	
	/*==========deleteByKey==============
	Delete key value in bst, by calling built in function of bst.
	Input: Key key
	*/
	void deleteByKey(Key key)
	{
		bst->deleteNode(key);
	}
	
	/*==========find==============
	find value in bst, by calling built in function of bst.
	Input: Key key
	return: Value value
	*/
	Value find(Key key)
	{
		return bst->get(key);
	}

};



#endif

