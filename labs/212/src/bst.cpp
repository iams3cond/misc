#include "bst.h"

bst::bst() : root(nullptr), count(0) {}

bst::~bst() { }

void bst::insert(T e) {
	insert(new bst_node(e));
}



bool bst::contains(T e) {
	bool result = count != 0;
	if (result) {
		bst_node *candidate = search_for(e);
		result = candidate->element == e;
	}
	return result;
}

// helper methods

void bst::dump_contents() const {
	if (count == 0) {
		std::cout << "empty" << std::endl;
	}
	else {
		in_order(root);   	
		std::cout << std::endl; 
	}
}

void bst::in_order(bst_node *e) const {
	if (e == nullptr) {
		return;
	}
	in_order(e->left);
	std::cout << e->element << " ";
	in_order(e->right);
}

bst_node *bst::search_for(T e) const {
	bst_node *result = root;
	bool absent = false;
	
	while (!absent && e != result->element) {
		if (e < result->element && result->left != nullptr) {
			result = result->left;
		}
		else if (e > result->element && result->right != nullptr) {
			result = result->right;
		}
		else {
			absent = true;
		}
	}
	return result;
}

