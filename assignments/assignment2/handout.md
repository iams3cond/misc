# AVL trees and the importance of being balanced

In lab we've already seen and implemented a simple binary search tree (BST). In lecture
as well as lab we've also encountered situations that illustrate one of the main 
shortcomings of such a structure: its inability to prevent arbitrarily skewed (lop-sided) 
trees, like those shown below.

<img src="https://github.com/dtwelch/misc/blob/master/assignments/assignment1/figures/skewed.png" width="400">

When bsts become skewed like this, we lose the desirable log-based searching performance 
characteristics such structures normally offer. To prevent this, variants of BSTs referred 
to as self balancing search trees were devised to keep the left and right subtrees 
"balanced", thus allowing one to retain the desired (searching) performance characteristics.

AVL trees are one specific way of addressing this problem. Named after 
[G.M. Adel’son-Vel’skii](https://en.wikipedia.org/wiki/Georgy_Adelson-Velsky) and 
[E.M. Landis](https://en.wikipedia.org/wiki/Evgenii_Landis)[1], these trees rely on a series 
of rotations performed on insertion of new nodes (and deletion of existing ones) to 
maintain a *tree balance property* which can be informally stated as follows:

>the height of the left subtree of any node differs from the height of the right subtree
>by no more than one

## Task

In this assignment you'll be transforming the (relatively) simple bst written in 
[lab #7]() into a self-balancing AVL tree.


To make visualization of such a tree easier, we're going to use DOT

## Refs

Adelson-Velskii, G.; E. M. Landis (1962). 
"An algorithm for the organization of information". 
*Proceedings of the USSR Academy of Sciences* 146: 263266.
(A translation by F.M. Goodspeed can be read [here]
(http://professor.ufabc.edu.br/~jesus.mena/courses/mc3305-2q-2015/AED2-10-avl-paper.pdf) )


