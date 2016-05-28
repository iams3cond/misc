// wdg 2014
#ifndef BINARY_SEARCH_NODE_H
#define BINARY_SEARCH_NODE_H

typedef int T;

class bst_node {
public:
	bst_node (T e) : 
		element(e), left(nullptr), right(nullptr), parent(nullptr) {}
		
	T element;
	bst_node *left, *right, *parent;
};

#endif