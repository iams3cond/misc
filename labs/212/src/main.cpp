#include "bst.h"

int main() {
	bst *t = new bst();
	/*
	t->insert(3);
	t->insert(2);
	t->insert(4);
	t->insert(6);
	t->insert(5);
	t->insert(8);
	//t->remove(8);
	*/
	

	t->insert(3);
	t->insert(2);
	t->insert(4);
	t->insert(6);
	t->insert(5);
	t->insert(8);
	t->remove(6);

	t->dump_contents();

	return 0;
}