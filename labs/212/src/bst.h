#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include "bst_node.h"

class bst {
public:
	bst();
	~bst();
	
	void insert(T e);		//insert e into this tree 
	
	bool remove(const T e);	//remove first element with key equal to e
	bool contains(T e);		//returns true iff e is in this bst; false otherwise
	void dump_contents() const; // print contents of this bst in order
	
private:
	bst_node *root;
	int count;
	
	bool insert(bst_node *e); //returns true iff e was inserted; false otherwise
	void in_order(bst_node *e) const;
	
	//searches this tree from the root down for a node containing element e. Returns
	//either the node if found, or, alternatively, the position where it should be 
	//attached; note this method assumes root != null, and will not return null itself.
	bst_node *search_for(T e) const; 
	
	//void deleteTree(bst_node *e);
};

#endif