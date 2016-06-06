# Graphs 

In this assignment you will write code that represents the mathematical notion of a 
directed acyclic graph (DAG) discussed in lecture. Along the way, you will construct a 
number of additional classes which will help you create an efficient implementation of 
Kruskal's well known greedy algorithm for constructing minimal spanning trees (MSTs).

This assignment is divided into three phases.

## Phase 1: implement the `DisjointSets` forest class

The first portion of this lab is to implement the *mimimal* disjoint set data structure, 
as summarized in the header below.

```c++
class DisjointSets
{
public:
	DisjointSets(int size);

	int find(int e) const;
	int find(int e);
    void unionSets(int u, int v);

private:
    vector<int> s;	//the parent array/list, all entries should be initialized to -1
};
```
Your solution should use *union by rank* and *path compression* optimizations, as described
in Weiss. Note that this particular disjoint set class has no `makeSet` or equivalent method.
Instead, singleton elements/sets are are implicit in the underlying array.

## Phase 2: 