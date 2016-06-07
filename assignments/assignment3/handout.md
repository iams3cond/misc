# Graphs 

In this assignment you will write code to represent the mathematical notion of a 
directed acyclic graph (DAG) discussed in lecture. Along the way, you will construct a 
number of additional, generic classes to aid in the implementation of Kruskal's
well known greedy algorithm for constructing minimal spanning trees (MSTs) -- which will ultimately
be implemented on top of the graph class you write.

This assignment is divided into three phases.

## Phase 1: implement a `DisjointSet` forest

The first portion of this assignment is to implement the disjoint set data structure discussed
at length in class and in Weiss. Our implementation will differ somewhat from that shown
in Weiss. 

The template header below, which you will provide an implementation of, should
incorporate *union-by-rank* and *path-compression* optimizations.

```c++
template <class T>
class DSNode
{
public:
	T* data;
	int rank;					
	DNode<T> *parent;
	DNode(T* e) : data(e), rank(0), parent(nullptr) 
	{}										
};

template <class T> 
class DisjointSets
{
	DSNode<T>* *elements;
	
	//max possible num of elements array & num of elements currently in the forest, respectively
	int capacity, length; 
	public:
		DisjointSets(int max_capacity = 10);	//default
		~DisjointSets();

		void makeSet(T* x);				//make a new singleton set containing data x
		void makeUnion(T* x, T* y);		//union the disjoint sets containing data x and y
		T* findSet(T* x);				//return the representative of the set containing x
		
		std::string display();		
	private:
		//finds and returns a node containing element x; null if not found.
		DSNode<T>* find(T* x); 
		
		//returns the representative element by recursively taking the parent of x
		DSNode<T>* findSet(DSNode<T> *x);	
		void link(DSNode<T> *x, DSNode<T> *y);
};
#include "DisjointSets.cpp"
```

For simplicity, include both `DSNode` and `DisjointSets` in the same `.h` file as it is
listed. 

To get you started, the proceeding section provides some rough pseudocode for some of the 
public and private methods you'll be writing.

### Public 

#### `makeUnion (T x, T y)`

```python
#union the disjoint sets containing x and y.
n1 = find node containing x 
n2 = find node containing y
link(representative element of n1, representative element of n2)
```

#### `makeSet (T x)`

```python
#make a new singleton set containing data x
if length == capacity then stop, error
create a new node n containing x
n of parent = n							#all nodes start life pointing to themselves
n of rank = 0							#singletons start rank 0
increment length						
```

#### `findSet (T x)`

```python
#finds and returns the representative of the set containing x
find the node containing x
find the representative of this node
return the representative node's data
```

### Private

And here's some (pretty) rough pseudocode for the `link` method that does union by rank.

#### `link(node x, node y)`

```python
#links two disjoint sets together
if the rank of x is greater than the rank of y then 
	x becomes the parent of y
otherwise y becomes the parent of x
	and additionally, if y's rank == x's rank then increment y's rank
```

### Testing

As usual, write unit tests (i.e. ones beyond the example below) for your implementation.
By `#include`(ing) `<cassert>` you can place asserts throughout your test program:

For example, one of your test methods might look like the following:

```c++
public void test_union1 {
	//first create a bunch of singleton sets
	forest.makeSet(aa);
	forest.makeSet(bb);
	forest.makeSet(cc);
	forest.makeSet(dd);
	forest.makeSet(ee);
	forest.makeSet(ff);
	forest.makeSet(gg);
	forest.makeSet(hh);

	//now link-em together
	forest.makeUnion(gg, bb);
	assert(forest.toString() == "0:0  1:1  2:0  3:0  4:0  5:0  6:0->1:1  7:0  ");

	forest.makeUnion(aa, ee);
	assert(forest.toString() == "0:0->4:1  1:1  2:0  3:0  4:1  5:0  6:0->1:1  7:0  ");

	forest.makeUnion(gg, ee);
	assert(forest.toString() == "0:0->4:2  1:1->4:2  2:0  3:0  4:2  5:0  6:0->1:1->4:2  7:0  ");

	forest.makeUnion(hh, dd);
	assert(forest.toString() == "0:0->4:2  1:1->4:2  2:0  3:1  4:2  5:0  6:0->1:1->4:2  7:0->3:1  ");	
}
```
Here's a visualization of the forest after the above call sequence:

<img src="https://github.com/dtwelch/misc/blob/master/assignments/assignment3/figures/disj_sets.png" width="650">

### Notes:

* You should write the private variant of `findSet` recursively. Think carefully
about the base case here.. What testable characteristic do all *root* nodes have?

* Because we're writing a generic template class, all methods in the implementation in the 
implementation must begin with the line: `template <class T> /* normal method declaration goes here */`. 
This applies to constructors, destructors, etc as well.




make a note about implementing template methods and compiling 
(.h includes the cpp, so compile .hs that contain template classes), other classes as normal.