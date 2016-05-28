#include "bst.h"

int main() {
	bst *T = new bst();
	
	T->insert(3);
	T->insert(2);
	T->insert(4);
	T->insert(6);
	T->insert(5);
	T->insert(8);
	
	T->dump_contents();

	return 0;
}