## Binary Search Trees

The objective of this lab is to implement some of the core algorithms behind the canonical 
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

![resulting bst](https://raw.githubusercontent.com/dtwelch/misc/master/labs/212/figures/bst.png)

Given just the raw inorder traversal output to work with, it can take a little time and 
practice to figure out how to visually construct the tree as it appears above. If
tree is relatively small, one relatively simple way to do so is to split the output in 
terms of subtrees. 

For example, since the tree above has an even number of nodes (greater than 2): 

>(left subtree) 2 3 4  |  	(right subtree) 5 6 8

Then simply think of the middle element in each subtree as the root:

![reconstructing](https://raw.githubusercontent.com/dtwelch/misc/master/labs/212/figures/split.png)

If you have a tree has an odd number of nodes, find the middle node in the output (this 
will be the topmost root) then proceeed to split each left and right subtree in the manner 
described above.

This isn't a very scalable or foolproof method by any means, but it's good enough to help
one draw out smaller, hand-built trees -- which is something you will likely want to do in
this lab.

### Task

You can find the starter kit for the lab [here](https://github.com/dtwelch/misc/tree/master/labs/212/src).
You are given a simple binary search tree class (in `bst.h`) which contains the following
methods:

```c++
public:
	void insert(T e);			//insert e into this tree 
	
	bool remove(const T e);		//remove first element with key equal to e
	bool contains(T e);			//returns true iff e is in this bst; false otherwise
	void dump_contents() const; // print contents of this bst in order

private:
	bool insert(bst_node *e); //returns true iff e was inserted; false otherwise
	void in_order(bst_node *e) const;
	bst_node *search_for(T e) const; 
```

You are to implement the `insert` and `remove` methods. You can do so either recursively 
or iteratively (though in lab we'll discuss the iterative approach for both).

#### `insert`

The procedure for inserting into a binary search tree, by far the easier of the two 
operations, really boils down to knowing exactly which existing node to hang the new 
node from. Once this existing node is found, all we then have to do is figure out on 
which side our new node should be hung (left or right -- what property defines this for us?)

To summarize, a sketch of the algorithm described above for inserting some node, 
say `e`, goes something like this:

```
is the tree empty? 
	if so, set root and increment the node count
otherwise
	find an existing node, j, in the tree from which to attach e (hint: read the header)
	if e.val < j.val
		increment count, and link up e
	elseif e.val > j.val
		increment count, link up e
	else
		error: duplicate 
```

#### `remove` 

Remove is considerably more complicated. As is typically of bigger, tougher problems, 
we'll break our solution into three distinct cases:



### closing thoughts: disadvantages, 