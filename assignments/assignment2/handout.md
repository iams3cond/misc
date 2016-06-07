# AVL trees and the importance of being balanced

<img src="https://github.com/dtwelch/misc/blob/master/assignments/assignment2/figures/cartoon.jpg" width="400">

In lab we've already seen and implemented a simple binary search tree (BST). In lecture
as well as lab we've also observed the main shortcoming of such a structure: its 
inability to prevent arbitrarily skewed (lop-sided) trees, such as those shown below.

<img src="https://github.com/dtwelch/misc/blob/master/assignments/assignment2/figures/skewed.png" width="650">

When BSTs become skewed, we lose the clean and fast log-based performance we would normally see under 
different configurations of the tree. To address this, a class of BSTs referred 
to as self balancing search trees were devised to ensure that left and right subtrees 
remain balanced across arbitrary sequences of modifications to the underlying tree, thus 
guaranteeing desirable performance characteristics.

AVL trees are merely one specific means of addressing this problem 
(there are numerous [others](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree)). Named after 
[G.M. Adel’son-Vel’skii](https://en.wikipedia.org/wiki/Georgy_Adelson-Velsky) and 
[E.M. Landis](https://en.wikipedia.org/wiki/Evgenii_Landis) [1], these trees rely on a series 
of rotations performed on insertion of new nodes (and deletion of existing ones) to 
maintain a *tree balance property* which can be (informally) stated as follows:

>the height of the left subtree of any node differs from the height of the right subtree
>by no more than one.

For additional information, and a general framework for the code you'll be writing in this
assignment, refer to [Weiss 4.4]
(https://people.cs.clemson.edu/~pargas/courses/cs212/common/notes/pdf/AVL.Notes.pdf).

## Task

In this assignment -- either from scratch or using your existing binary search tree created 
in [lab #7](https://github.com/dtwelch/misc/blob/master/labs/212/lab7.md) as a starting point -- 
you'll produce a working, self-balancing AVL tree that supports insert, delete, several 
utility methods, as well as a method for visualizing resultant trees using a tool/lib 
called *Graphviz*.

The following is a list of methods you will need to implement.

```c++
public:
	avl();
	~avl();						//should call delete_tree on the root
	
    const T find_min() const;	//returns the minimum element in this tree; throws underflow_exception if tree is empty
    const T find_max() const;				
    bool is_empty() const;		//returns true iff this tree has no nodes; false otherwise
    void insert(T item);		//inserts item into the tree; throws dup_element_exception if already present
    void remove(T item);		//removes item from the tree; 
    void dump_contents() const; //prints an in-order traversal of this tree's elements
    
    //writes a graphviz (dot) file to the current directory. Don't attempt to implement this
    //until you've read task step #3. 
    void dump_dot(std::string filename); 
    
    
private:	
	void insert(const T item, avl_node *&current);

	void rotate_with_left_child(avl_node *&k2);
	void rotate_with_right_child(avl_node *&k1);
	void double_with_left_child(avl_node *&k3);
	void double_with_right_child(avl_node *&k1);
	
	void in_order(avl_node *e) const;
	avl_node* find_min(avl_node *e) const;
	avl_node* find_max(avl_node *e) const;

	void balance(avl_node *&e);
	void delete_tree(avl_node *&e);			//deletes all nodes in (sub)tree e
	int height(avl_node *e) const;			//returns the height of node e
	
	//A recursive method that returns a string containing a dot-representation 
	//of this tree. Don't attempt to implement this until you've read task step #3. 
	std::string build_dot_content(std::stringstream &o, 
								  avl_node *e, 
								  int index_lab) const;
```

## Suggested steps (in order)

### 1. `insert` + supporting methods

As with regular BSTs, your first priority (aside from getting 
barebone classes setup and compiling) should revolve around getting the `insert` method 
working.

This will require, in turn, implementations of the following:

* the four tree rotations
* `balance`
* `height`

#### a note on `balance`
 
This method is really an optional one intended to encapsulate all the rotations needed for both 
insertions and deletions. That is, should you choose to use/implement this method, it should simply 
be called at the very bottom of the insert and remove methods. For example, here's a 
rough sketch of Weiss's (original) insert method refactored using the `balance` method:

```python
insert (T item, node current)

	if (current == nullptr):
		current = new avl_node(item, nullptr, nullptr)
	else if (item < current of element):
		insert(item, current of left)
	else if (item > current of element):
		insert(item, current of right)
	else 
		#error dup element
	balance(current)
```

Thus, all the logic present in the book (left out of the pseudocode method above) should be 
put into `balance` (complete with the `if`s and `else`s). You can however 
stick with the `insert` code exactly as it appears in Weiss if you prefer.

### 2. `remove` + remaining header methods

Once insert has been run several times (remember to print output using the `in_order` method) now is a good
time to begin working on `remove` and the remaining methods. Here's some tentative pseudocode for `remove`.

|note: skip these for now|
|-------------|
|It's a good idea to hold off on writing implementations for `build_dot_content` and `dump_dot` until you've read the next section.|

```python
remove (T item, node current)
	if current = null: 
		return
	if item < current of element:
		remove(item, current of left)
	else if item > current of element:
		remove(item, current of right)
	else if current has two children:
		current of element = the minimum element in current's right subtree
		remove(current of element, current of right)
	else
		avl_node old = current
		current = current of left if not null; current of right otherwise.
		delete old
	balance(current)
```

### 3. Visual verification

To make testing the tree easier (and just for fun), we're going to use DOT notation to produce a nice 
visualization of the resultant tree. To do this, we utilize a graph visualization
tool/library referred to as [Graphviz](http://www.graphviz.org/).

*Installation and usage can differ from platform to platform. That said, it's a pretty 
popular tool so googling should turn up a number of results. Needless to say, 
contact me (`dtwelch@g.clemson.edu`) if you need some help with the setup, and I'll do what I can.*

For example, given the following client code:
```c++
avl *t = new avl();
t->insert(4);
t->insert(9);
t->insert(2);
t->insert(1);
t->insert(0);
t->insert(10);

t->dump_contents();
t->dump_dot("avl_test.dot");
```
here is a resulting visualization:

<img src="https://github.com/dtwelch/misc/blob/master/assignments/assignment2/figures/avl_viz.png" width="400">

.. and here is the dot code we generated to tell Graphviz how to draw the tree above:

```
digraph AVL {
	graph [dpi=150]
	nodesep=0.3;
    ranksep=0.2;
    margin=0.1;
    node [shape=circle fontname="Helvetica";];
    edge [arrowsize=0.8];
    
    //below is the code that actually makes the graph, everything above this comment 
    //is boilerplate and can be hardcoded in dump_dot(..), the internal method
    //"build_dot_content()" returns a string containing the lines below (generated from the tree)
    node1 [label="4"];
    node1 -> node2;
    node2 [label="1"];
    node2 -> node4;
    node4 [label="0"];
    node2 -> node5;
    node5 [label="2"];
    node1 -> node3;
    node3 [label="9"];
    node3 -> node7;
    node7 [label="10"];
}
```

Calling 
```c++
dump_dot("avl_viz.dot")
``` 
in your main driver should write a dot file 
(in this case, `avl_viz.dot`) to the current directory. You can tell Graphviz to transform 
the dot file into a .png with the following command:

> $Daniels-MacBook:src daniel$ dot avl_viz.dot | neato -n -Tpng -o avl_viz.png

After this, you should see `avl_viz.png` in your current directory.

## Notes, hints, etc

* If you use the existing BST class you've written in lab, but intend to follow the code 
Weiss provides in the notes, you can safely remove the `parent` pointer from your node 
class/struct.

* You will need a way of uniquely numbering the nodes in order to write the output 
dot file correctly. One way is to simply say:
```c++
int lchild = 2 * index_lab;
int rchild = 2 * index_lab + 1;
```
before you recurse, then `lchild` (or `rchild`, 
depending on which child your recursing down into) should be passed in for `index_lab` when
the recursive call is made.

## References

Adelson-Velskii, G.; E. M. Landis (1962). 
"An algorithm for the organization of information". 
*Proceedings of the USSR Academy of Sciences* 146: 263266.
(If you're curious, a translation by F.M. Goodspeed can be read [here]
(http://professor.ufabc.edu.br/~jesus.mena/courses/mc3305-2q-2015/AED2-10-avl-paper.pdf) )


