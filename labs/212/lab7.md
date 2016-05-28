## Binary Search Trees

The objective of this lab is to implement the core algorithms behind the canonical 
binary search tree data structure discussed in lecture: namely the `insert` and `remove` 
methods.

Recall that a binary search tree (BST) is a rooted tree in which every node has at
most two children (hence the 'binary' in the name). In addition to having only the proper
number of children, each node must conform to the following property:

> values of the left children are smaller than the parent node's value, while right 
children's values are are larger

### Example

The following client code constructs a small binary search tree with six nodes

```c++
int main() {
	bst *t = new bst();
	
	t->insert(3); t->insert(2); t->insert(4); t->insert(6); t->insert(5); t->insert(8);
	t->dump_contents();
}
```

Once the tree is built, a call to `dump_contents` will print an in-order traversal of
`t` to the terminal.
```
> $Daniels-MacBook:src daniel$ ./a.out
> 2 3 4 5 6 8 
```

#### interpreting the output

Below is a visualization of the tree written above.

![resulting bst](https://github.com/Welchd1/misc/labs/212/figures/bst.png)

Given just the raw inorder traversal output to work with, it can take a little time and 
practice to figure out how to visually construct the tree as it appears above. If
tree is relatively small, one relatively simple way to do so is to split the output in 
terms of subtrees. 

For example, since the tree above has an even number of nodes (greater than 2): 

>(left subtree) 2 3 4  |  	(right subtree) 5 6 8

Then simply think of the middle element in each subtree as the root:

![reconstructing](https://github.com/Welchd1/misc/labs/212/figures/split.png)

If you have a tree has an odd number of nodes, find the middle node in the output (this 
will be the topmost root) then proceeed to split each left and right subtree in the manner 
described above.

This isn't a very scalable or foolproof method by any means, but it's good enough to help
one draw out smaller, hand-built trees -- which is something you will likely want to do in
this lab.  

## Task

You can find the starter kit for the lab [here](https://github.com/dtwelch/misc/tree/master/labs/212/src).
This contains `bst.h` 

### closing thoughts: disadvantages, 