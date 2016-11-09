// 
// 
// 

#include "Node.h"

/*==========Node==============
	Constructor of Node
	input: int inbeat, char innote
*/
Node::Node(int inbeat, char innote)
{
	beat = inbeat;
	note = innote;
}

/*==========Node==============
	Constructor of Node
*/
Node::Node()
{
	beat = NULL;
	note = NULL;
}

/*==========~Node==============
	Disstructor of Node
*/
Node::~Node()
{

}


