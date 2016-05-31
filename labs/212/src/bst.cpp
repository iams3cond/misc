#include "bst.h"

bst::bst() : root(nullptr), count(0) {}

bst::~bst() { }

void bst::insert(T e) {
	insert(new bst_node(e));
}

bool bst::insert(bst_node *candidate) {
	if (count == 0) {
		root = candidate;
		count++;
	}
	else {
		bst_node *posn_to_insert = search_for(candidate->element);
		
		if (candidate->element < posn_to_insert->element) {
			count++;
			posn_to_insert->left = candidate;
			candidate->parent = posn_to_insert;
		}
		else if (candidate->element > posn_to_insert->element) {
			count++;
			posn_to_insert->right = candidate;
			candidate->parent = posn_to_insert;
		}
		else {	//we've found a duplicate...
			std::cout << "duplicate node: " << candidate->element << std::endl;
			return false;
		}
	}
	return true;
}

bool bst::remove(T e) {
	if(root == nullptr) {
		std::cout << "trying to remove from empty tree.." << std::endl;
		return false;
	}
	
	if (count == 1 && root->element == e) {
	   root = nullptr;
	   count--;
	   return true;
	}
	
	if (e == root->element && (root->left == nullptr || root->right == nullptr)) {
		// root deleted
		bst_node *toBeDeleted = root;
		if(root->left != nullptr) root = root->left;
		else root = root->right;
		root->parent = nullptr;
		count--;
		delete toBeDeleted;
		return true;
	} 
   
	//root not deleted
	bst_node* current = search_for(e);
	if(current->element != e || current == nullptr) return false;
	
	if(current->right != nullptr && current->left != nullptr){
		bst_node* temp = current;
		current = current->right;
      
		while(current->left != nullptr) {
			current = current->left;
		}
		temp->element = current->element;
	}
	bst_node* parent_curr = current->parent;
	bst_node* to_be_deleted = current;
   
	if(current->left != nullptr) current = current->left;
	else current = current->right;

	if (to_be_deleted == parent_curr->left) parent_curr->left = current;
	else parent_curr->right = current;

	//current will be null here if we're deleting a leaf. 
	if (current != nullptr) current->parent = parent_curr;
	count--;
   
	delete to_be_deleted;
	return true;
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

