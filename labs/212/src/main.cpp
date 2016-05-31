#include "bst.h"

int main() {
	bst *t = new bst();

	t->insert(3);

	
	std::cout << "Before: " << std::endl;
	t->dump_contents();
	
	std::cout << "After: " << std::endl;	
	t->remove(3);
	t->dump_contents();


	return 0;
}