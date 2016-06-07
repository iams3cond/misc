# Graphs 

In this assignment you will write code to represent the mathematical notion of a 
directed acyclic graph (DAG) discussed in lecture. Along the way, you will construct a 
number of additional, generic classes to aid in the implementation of Kruskal's
well known algorithm for constructing minimal spanning trees (MSTs) -- which will ultimately
be implemented on top of the graph class you write.

This assignment is divided into three phases.

## Phase 1: implement a `DisjointSet` forest

The template header is given below. The implementation, which you will provide should 
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
	int capacity, length; //size of elements array & num of elements in the forest, respectively
	
	public:
		DisjointSets(int max_capacity = 10);	//default
		~DisjointSets();

		void makeSet(T* x);				//make a new singleton set containing data x
		void makeUnion(T* x, T* y);		//union the disjoint sets containing data x and y
		T* findSet(T* x);				//return the representative of the set containing x
		
		std::string display();		

	private:
		//searches elements for a node containing x, if found, return it; null otherwise
		DSNode<T>* find(T* x); 
		
		//returns the representative element by recursively taking the parent of x
		DSNode<T>* findSet(DSNode<T> *x);	
		void link(DSNode<T> *x, DSNode<T> *y);
};
#include "DisjointSets.cpp"
```

For simplicity, include both `DSNode` and `DisjointSets` in the same `.h` file as it is
listed. 

To get you started, here is some rough pseudocode core algorithms you'll need to write.

### `makeUnion`

```python
#union the disjoint sets containing x and y.
def makeUnion(T x, T y):
	n1 = find node containing x 
	n2 = find node containing y
	link(representative element of n1, representative element of n2)
```

### `makeSet`

```python
def makeSet(T x):
	if length == capacity then stop, error
	
	DNode<T> *newnode = new DNode<T>(x);	// make a new node
	elements[length] = newnode;			// pop it into whatever index length in our array 
	newnode->parent = newnode;				// parent should point to itself
	newnode->rank = 0;						// singletons rank should be zero...
	length++;									// increment length-- next node goes into next spot in 'elements'
}
```