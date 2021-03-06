# Graphs 

In this assignment you will write code to represent the mathematical notion of a 
directed acyclic graph (DAG) discussed in lecture. Along the way, you will construct a 
number of additional classes to aid in the implementation of Kruskal's
well known greedy algorithm for constructing minimal spanning trees (MSTs) -- which will ultimately
be implemented on top of the graph class you write.

This assignment is broken down into three phases, plus an optional fourth phase.

## Phase 1: implement a `DisjointSet` forest

The first portion of this assignment is to implement the disjoint set data structure discussed
at length in class and in Weiss. Our implementation will differ somewhat from that shown
in Weiss. 

The template header below, which you will provide an implementation of, should
incorporate *union-by-rank* and *path-compression* optimizations.

```c++
//disjoint_sets.h

template <class T>
class DSNode
{
public:
	T* data;
	int rank;					
	DSNode<T> *parent;
	DSNode(T* e) : data(e), rank(0), parent(nullptr) 
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
		
		std::string toString();		
	private:
		//finds and returns a node containing element x; null if not found.
		DSNode<T>* find(T* x); 
		
		//returns the representative element by recursively taking the parent of x
		DSNode<T>* findSet(DSNode<T> *x);	
		void link(DSNode<T> *x, DSNode<T> *y);
};
#include "disjoint_sets.cpp"
```

For simplicity, include both `DSNode` and `DisjointSets` in the same `.h` file as it is
listed. Also take note of the inclusion of `"disjoint_sets.cpp"` in the header. For (generic) 
template classes in c++, this is the standard way of keeping headers separate from 
implementations. This means **when you go to compile, you should do this:**

```
g++ -Wall -std=c++11 some_main.cpp disjoint_sets.h
```

In this case, the disjoint sets header automatically pulls in the .cpp -- which effectively places both the header and implementation in the same file (c++ [requires](http://stackoverflow.com/questions/1724036/splitting-templated-c-classes-into-hpp-cpp-files-is-it-possible) this of template classes).

To get you started, the proceeding section provides some rough pseudocode of the 
public and private methods you'll be writing in this phase.

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

And here's some (pretty) rough pseudocode for the `link` method and the `findSet` method which is what carries out path compression.

#### `link(node x, node y)`

```python
#links two disjoint sets together
if the rank of x is greater than the rank of y then 
	x becomes the parent of y
otherwise y becomes the parent of x
	and additionally, if y's rank == x's rank then increment y's rank
```

#### `findSet(node x)`

```python
if x is not equal to x of parent:
	x of parent = findSet(x of parent)
return x of parent;
```

### Testing

As usual, write unit tests (i.e. ones beyond the example below) for your implementation.
By `#include`(ing) `<cassert>` you can place asserts throughout your test program.

For example, one of your test methods might look like the following:

```c++
public void test_union1 {
	DisjointSets<int> forest(10);
	int a = 0;  int b = 1;  int c = 2;  int d = 3;  int e = 4;
	int f = 5;  int g = 6;  int h = 7;
	
	int *aa = &a;  int *bb = &b;  int *cc = &c;  int *dd = &d;  int *ee = &e;
	int *ff = &f;  int *gg = &g;  int *hh = &h;
	
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
And of course, don't forget to actually call your test methods from your `main()`.
Here's a visualization of the forest after the above call sequence, followed by the output
your `toString()` method should return.

<img src="https://github.com/dtwelch/misc/blob/master/assignments/assignment3/figures/disj_sets.png" width="300">

```
0:0->4:2
1:1->4:2
2:0
3:1
4:2
5:0
6:0->1:1->4:2  
7:0->3:1
```
Here, each `(i:j)` pair represents a data element `i` and its rank `j`. It's up to you whether you
print this all on one space delimited line or with newlines (as above). For testing purposes
however, it might be helpful to have an overloaded version of `toString` which takes a
`bool` indicating whether or not the returned string should contain newlines. For example:

```c++
//an overloaded toString which assumes the user wants newlines in the resulting string
std::string DisjointSets::toString() {
	return toString(true);
}

std::string DisjointSets::toString(bool shouldContainNewlines) {
	...
}
```
### Notes:

* Should you choose to write the private variant of `findSet` recursively. Think carefully
about the base case. What testable characteristic do all *root* nodes have? (**update: see pseudocode above for findSet(..)**)

* Because we're writing a generic template class, all methods in the implementation must begin with the line: `template <class T> /* normal method declaration goes here */`. This applies to constructors, destructors, etc as well.

## Phase 2: implementing a graph

### class `Edge`
First construct a weighted `Edge` class which stores two ints representing the ends of an edge, along with a weight, `w`. Your `Edge` class should also support the `<<` operator and overload (at a minimum) the `<=` and `>=` relational operators. 

### class `UndirectedWeightedGraph`
The graph itself should be represented as an adjacency list. The constructor should take an int representing the number of nodes in the graph. There should be methods for adding and removing edges, and their parameters should just be ints describing the ends of the edge your adding (or removing). Note that the add method should also take a weight for the edge being added.

There should also be a method `edges()` that returns all `Edge`s currently in the graph, as well as a method `adjacentTo(..)` that takes a vertex (int) and returns all incident `Edge`s -- naturally, there should also be methods for retrieving the number of edges and vertices currently in the graph.

Finally, overload the output stream (`<<`) operator. Use your best judgement when determining the way the output should look. I suggest a scheme like the following:

>[node #] : [node #'s adjacency list]

where each portion in square brackets would be replaced by real info.

### Testing:

Remember to use `assert`s to write some basic unit tests for your graph class to ensure it's working properly.

### Notes:

* It's up to you to figure out how you want to internally organize all of this. In terms of the 'adjacency list' representation, you can always use an array where each index *i* (representing the name of a given node) holds a container for storing the edges adjacent to it. Though I think its preferable to simply use a vector of vectors. Less hassle.
* Assume the int labels on all nodes are unique.
* Since we're using ints within some range from `0..vertices`, *make sure you check that the indices passed into the various methods of this class are in range. It's probably best to have a helper method that does so.*

## Phase 3: graph algorithms

Now that we have a graph class and disjoint set at our disposal, create a separate class called `GraphAlgorithms` that includes the following methods.

```c++
static std::vector<Edge*> kruskalFindMST(const UndirectedWeightedGraph *g) { .. }
```
This method should use Kruskal's algorithm to construct a minimum spanning tree from a weighted, undirected graph `g`. It should return the list of edges forming a MST in `g`. You will need to use your disjoint set class here, in addition to a priority queue for sorting the edges by weight (I suggest using `std::priority_queue` for expediency, though if your looking for an extra challenge, consult the optional phase 4). Take your time implementing this. There are a number of details that tend to get hidden under some very simple looking pseudocode.

```c++
static void dfs(const UndirectedWeightedGraph *g) { .. }
static void bfs(const UndirectedWeightedGraph *g) { .. }
```

These two methods should implement depth (and breadth) first search. Print the vertices in the order they are visited.

In this case, because we're just writing a bunch of static methods, this class should have no constructor; that is you are encouraged to implement all of these methods inline in the `.h` file for the `GraphAlgorithms` class.

### Testing

Finally, have a main driver in a separate .cpp that calls these static methods on some sample graphs. As usual write some tests for these methods. It might be somewhat difficult writing tests for kruskal's algorithm as its behavior is relational (meaning there might be multiple valid minimum spanning trees in a given graph). So for testing purposes, it's probably a good idea to find graphs where you manually enumerate all answers and test the output against those answers.

```c++
int main() {
	testDfs1();
	testDfs2();
	testDfs3();
	testKruskal1();
	testKruskal2();
	testKruskal3();
	..
}

void testKruskal1() {
	UndirectedWeightedGraph *g = new UndirectedWeightedGraph(4);
	//... add edges
	GraphAlgorithms::kruskalFindMST(g);
}
```

## Phase 4: implement a minimum priority queue using a heap (extra credit)

Instead of using the std template library's queue, write your own. You have some flexibility in determining how you want to go about this with the understanding that you are not to simply copy someone else's implementation (or translate) a bloggers implementation in another language. I suggest consulting the pseudocode provided in a [canonical algorithms textbook such Cormen Leiserson Rivest and Stein (clrs)](http://www.amazon.com/Introduction-Algorithms-3rd-MIT-Press/dp/0262033844), or other popular textbooks.

*I suggest completing the core assignment as written above. That is, get phases 1-3 done, then come back and do this if you feel up to it. (then of course retro-fit the code you previously wrote to utilize your new priority queue -- I will consider this a sufficient test of your replacement class).*
