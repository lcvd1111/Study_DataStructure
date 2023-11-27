This repository contains the work created during the study of basic Data Structures. I used the book 'Data Structures using C (2nd)(2018) by Reema Thareja' as my learning resource.


[Book Overview]

: This is an overview of the textbook I used.(Reema Thareja book)
I skipped writing down the concepts related to 'linked list' in the below overveiw.
It is bc I thought it should be regarded as a basic syntax of the language like 'array', rather than a specific data structure.

1. Stack (Chatper 7)
  1-1. Definition of 'Stack ADT(Abstract Data Type)'
  1-2. Implementation of Stack
    1-2-1. Implementation using array.
	1-2-2. Implementation using linked list.
  1-3. Application of Stack
    1-3-1. Parenthesis correctness checking algorithm.
	1-3-2. Mathematical expression parsing alogrihtm.(=Shunting Yard algorithm)
	1-3-3. Generally, it is useful for "reverting the object's value to the most recent one". For example, 'Ctrl+z' in word processor. 
    1-3-4. Analysis of the recursive function by writing down the 'Status of Call Stack(=Stack Segment of the process memory)'.


2. Queue (Chatper 8)
  2-1. Definition of 'Queue ADT(Abstract Data Type)'
  2-2. Implementation of Queue
    2-2-1. Implementation using array. It is usually done by implementing 'Circualr Queue'. You should know the reason.
	2-2-2. Implementation using linked list.
  2-3. Variations of Queue
    2-3-1. Deque ADT(Double Ended Queue)
	2-3-2. Priority Queue ADT (->It is usually implemented by the 'heap' data structure statudied later)
  2-4. Application of Queue
    : It's most often uses are 'buffer for the communication between two entity'.


3. Basic Tree (Chapter 9, 10)
  3-1. Definition of Basic Terms and properties
    3-1-1. Definitions of 'Tree', 'Root', 'Leaf', 'Parent', 'Child', 'Uncle', 'Sibling', 'Ancestors', 'Descendants', 'Height', 'Depth', 'Level'
	3-1-2. Definitions of 'Binary Tree', 'Complete Binary Tree', 'Full Binary Tree', 'Perfect Binary Tree', 'Extended Binary tree'
	3-1-3. (Property) Height of the Complete Binary tree with n number of nodes.
	3-1-4. (Property) Number of internal nodes of Full Binary tree with n number of leaf nodes.
  3-2. Implementation of Binary Tree
    3-2-1. Implementation using array.(It is usually used for 'complete binary tree', including the binary heap.)
	3-2-2. Implementation using linked list.
  3-3. Algorithm for converting general trees to binary trees
  3-4. Algorithm for traversing the binary tree
    3-4-1. DFS based algorithms -> You must be able to implement all of them both exploiting 'user-created stack' and 'recursive function'.
	  3-4-1-1. Pre-Order Traversal
	  3-4-1-2. In-Order Traversal
	  3-4-1-3. Post-Order Traversal
    3-4-2. BFS based algorithms
	  : Level-Order Traversal
  3-5. Algorithm for reconstructing the binary tree by means of traversal result.
  3-6. Algorithm for binary tree analysis. (ex> Finding the height, Finding the number of internal nodes, Making the mirrored binary tree, etc...)
  3-7. Application of binary Tree: Huffman Coding.


4. Advanced Binary Tree(Almost about BST) (Chapter 10)
  4-1. Threaded Tree
  4-2. Basic Binary Search Tree(BST)
	4-2-1. Definition of 'Binary Search Tree'(BST) Data Structure.
	4-2-2. Algorithm for implementing 'Search(BST, x)' function.
	  4-2-2-1. Time Complexity of this algorithm.
	4-2-3. Algorithm for implementing 'Insert(BST, x)' function.
	  4-2-3-2. Time Complextiy of this algorithm.
	4-2-4. Algorithm for implementing 'Delete(BST, x)' function.
	  4-2-4-2. Time Complextiy of this algorithm.
  4-3. AVL BST
    4-3-1. Definition of 'AVL BST' Data Structure.
	4-3-2. Algorithm for implementing 'Insert(AVL_BST, x)' function.
	  4-3-2-1. Time Complexity of this algorithm.
	4-3-3. Algorithm for implementing 'Delete(AVL_BST, x)' function.
	  4-3-3-1. Time Complexity of this algorithm.
  4-4. Red-Black BST
    4-4-1. Definition of 'Red-Balck BST' Data Structure.
    4-4-2. Algorithm for implementing 'Insert(RB_BST, x)' function.
	  4-4-2-1. Time Complexity of this algorithm.
	4-4-3. Algorithm for implementing 'Delete(RB_BST, x)' function.
	  4-4-3-1. Time Complexity of this algorithm.
  4-5. Comparison between AVL BST and RB BST
    : For frequent 'Search()', AVL BST is better.
	For frequent 'Insert()' and 'Delete()', RB BST is better.
  4-6. Splay BST
    4-6-1. Definition of 'Splay BST' Data Structure.
	4-6-2. Algorithm for implementing 'Search(Splay_BST, x)' function.
	  4-6-2-1. Time Complexity of this algorithm.
	4-6-3. Algorithm for implementing 'Insert(Splay_BST, x)' function.
	  4-6-3-1. Time Complexity of this algorithm.
	4-6-4. Algorithm for implementing 'Delete(Splay_BST, x)' function.
	  4-6-4-1. Time Complexity of this algorithm.
  4-7. Application of BST (It is not written in the textbook.)
	: You can implement 'Set ADT' and 'Map(=Associative Array) ADT' by means of binary search tree data structure.
	This is also possible by using Hashmap too. You must know the benefit of using BST over Hashmap for implementing the set and map.
	It is a 'time compelxity' in the worst situation, and the 'Well-Sorted' feature.


5. Multiway Search Tree


6. Heap
  6-1. Binary Heap
    6-1-1. Definition of 'Binary Heap' data structure.
	6-1-2. Algorithm for implementing "Priority Queue ADT's Enqueue operation" using binary heap data structure.
	  6-1-2-1. Time Complexity of this algorithm.
	6-1-3. Algorithm for implementing "Priority Queue ADT's Dequeue operation" using binary heap data structure.
	  6-1-3-1. Time Complexity of this algorithm.
  6-2. Binomial Heap
    6-2-1. Defintion of 'Binomial Tree' and Definition of 'Binomial Heap' data structure.
	  6-2-1-1 (Property) 'Height' and 'Number of nodes' in 'n-order binomial tree'.
	  6-2-1-2 (Property) Finding the order of every each binomial tree included in the given binomial heap which consists of n number of nodes.
	  6-2-1-3 (Property) Upperbound of the number of trees in the given binomail heap which consists of n number of nodes.
	6-2-2. Algorihtm for implementing 'Merge(Heap1, Heap2)' function toward Binomial heap data structure.
	  6-2-2-1. Time Complexity of this algorithm.
	6-2-3. Algorithm for implementing "Priority Queue ADT's Enqueue operation" using binomial heap data structure.
	  6-2-3-1. Time Complexity of this algorithm.
	6-2-4. Algorithm for implementing "Priority Queue ADT's Dequeue operation" using binomial heap data structure.
	  6-2-4-1. Time Complexity of this algorithm.
  6-3. Fibonacci Heap
    6-3-1. Definition of 'Fibonacci Heap' data structure.
	6-3-2. Code level implementation of 'Fibonacci Heap' data structure.
	6-3-3. Algorihtm for implementing 'Merge(Heap1, Heap2)' function toward Fibonacci heap data structure.
	  6-3-3-1. Time Complexity of this algorithm.
	6-3-4. Algorithm for implementing "Priority Queue ADT's Enqueue operation" using Fibonacci heap data structure.
	  6-3-4-1. Time Complexity of this algorithm.
	6-3-5. Algorithm for implementing "Priority Queue ADT's Dequeue operation" using Fibonacci heap data structure.
	  6-3-5-1. Time Complexity of this algorithm.

7. Graph
  7-1. Defintions of basic terms.
    7-1-1. Defintions of 'Undriected Graph', 'Directed Graph', 'Degree', 'In/Out Degree', 'Sink/Source', 'Pendant Vertex', 'Isolated Vertex', 'K-regular Graph', 'Subgraph', 'Complete Graph'.
	7-1-2. Definitions of 'Path', 'Circuit', 'Simple Path', 'Cycle', 'Connected undirected graph', 'Bi-Laterally connected directed graph', 'Uni-Laterally connected directed graph', 'Weakly-Connected directed graph', 'Articular point(=Cut vertex)', 'Bridge', 'Bi-Connected graph'.
  7-2. Algorithm for finding transitive closure using Backtracking Bruteforce.
    : It is virtually equivalent to FloydWarshall Algorithm.
  7-3. Algorithm for traversing the graph.
    7-3-1. DFS
	7-3-2. BFS
	  7-3-2-1. Application of BFS: Finding the shortest path in unweighted graph.
  7-4. Topological Sorting of given Directed Acyclic Graph(DAG)
	7-4-1. Definition of 'Topological Sorting of given Directed Acyclic Graph'.
	  7-4-1-1. (Property) Existence, Non-Existence, Non-Uniqueness of Topological sorting.
	7-4-2. Algorithm for finding the 'Topological Sorting of given Directed Acyclic Graph'.
	7-4-3. Application of Topological Sorting: Scheduling.
  7-5. Minimum Spanning Tree(MST) of given undirected graph
    7-5-1. Defintion of 'Spanning Tree' of given undirected graph, Definition of 'Minimum Spanning Tree' of given undirected graph.
	  7-5-1-1. (Property) Existence, Non-Uniqueness, Uniqueness of MST.
	  7-5-1-2. (Property) Number of edges in MST with n number of vertices.
	7-5-2. Prim's Algorithm
	  7-5-2-1. Time Complexity of Prim's Algorihtm.
	7-5-3. Kruskal's Algorihtm
	  7-5-3-1. Time Complexity of Kruskal's Algorithm.
  7-6. Finding the shortest path of given weighted graph
    7-6-1. Dijkstra's Algorithm
	  7-6-1-1. Time Complexity of Dijkstra's Algorihtm.
	  7-6-1-2. Difference between Dijkstra's Algorithm and Prim's Algorithm.
	  7-6-1-3. Limit of Dijkstra's Algorithm: It is impossible when there is a negative weighted edge.
	  7-6-1-4. Finding the 'actual shortest paths', but not only the 'length of the shortest paths' using Dijkstra's Algorithm. -> You need to exploit the 'Predecessor Array'.
	7-6-2. Roy-Floyd-Warshall Algorithm
	  7-6-2-1. Time Complexity of Floyd's Algorihtm.
	  7-6-2-2. Finding the 'acutal shortest paths', but not only the 'length of the shortest paths' using Floyd's Algorithm. -> You need to exploit the 'Successor Matrix'.

8. Sorting and Searching Algorithms

9. Hashmap


[Implementations List].

.
.
.

