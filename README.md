# Hash-table-using-linked-list-and-Binary-search-tree

Program 4
Programming Assignment #4
80 points (+10 extra credit available)

Due Date/Time:

Your project is due on Thursday, May 4th, 11:59 p.m.  Note that this is the last day of our class for the semester. This date was selected to give you as much time as possible, not to increase your burden at the end of the semester.

Start early and complete your project early.  Why?  Early submissions are eligible for extra credit points!

          +10 points, if turned in by May 2st, 11:59 p.m.

          +05 points, if turned in by May 3rd, 11:59 p.m.

The Project:

The data structures we have studied previously are not suitable for managing large data sets.  For this assignment, you will implement two structures:

Hash Table (using Linked List)
Binary Search Tree
Your project will consist of the following files

HashTable.h A hash table definition header file, which is provided.
HashTable.cpp The hash table implementation with chaining.
LinkedList.h  A list ADT, which is provided.
LinkedList.cpp   The linked list, for which LinkedList.h is provided. 
BinarySearchTree.h  A Binary Search Tree definition, which is provided.
BinarySearchTree.cpp  The Binary Search Tree implementation.
Additional Programming helps (guidelines and some issues students encountered)

Binary Search Tree application
Implement BinarySearchTree.cpp
Obtain code for BinarySearchTree.h Download BinarySearchTree.h(available on Canvas).

Supply pre- and post- conditions for each function.
Note: The function height has no parameters and returns the height of the tree which is defined as the maximum of the heights of all nodes.  The height of a node is the number of edges between it and the root node.

Note: The function size has no parameters and returns the number of nodes in the tree.

Note: The function remove should use the successor to replace a node with two child nodes.

Note: The function makeEmpty removes all the nodes from the tree and returns (deallocates) the memory used by the nodes for reuse.  The makeEmpty function ultimately sets the root pointer value to NULL.

Implement the member and friend functions and overloaded operators.  Note that some of the functions listed here are already implemented in examples in class. You should test your code thoroughly.

Hints:

1)  Consider maintaining a private size variable that is increased by insertion and decreased by deletion, and whose value is returned by the size() function.  Alternatively, a traversal of the tree when the function is called could also calculate the size of the tree.  Similar techniques could determine the height of the tree.

2)  Do these tasks a few members at a time.  Compile and test after doing each group of a few members. You will be glad you did it this way!

3)  Before you write the operator =, and the copy constructor, note that their jobs have a common task:  duplicating another tree.  Write a copyTree function that abstracts out the common task of these operations, then use it to implement these functions.

4)  The makeEmpty and the destructor have a common tree task.

Hash Table application
Implement LinkedList.cpp and HashTable.cpp
Obtain code for LinkedList.h Download LinkedList.h, and HashTable.h Download HashTable.h(available on Canvas).

Implement a singly linked list class LinkedList.cpp as defined in LinkedList.h.  This will supply the chaining needed for the HashTable class.
Implement a chained hash table HashTable.cpp as defined in HashTable.h.
Additional Details:

Your project will consist of exactly the files/classes named in this assignment. You may not have any additional classes or public methods.  You may add private methods/variables to the header file (the BinarySearchTree class will certainly need some). 
Your HashTable implementation must use chaining, and use class LinkedList
Your implementation methods should be as efficient as possible.
Each source code file should begin with comments, including your name and Red ID.
Your class names and methods and method signatures must match the specifications exactly.
Projects that fail to compile will receive very little or no credit.
Your project will be graded with a test suite and will use the instructor's versions of the supplied header files.
Additional help (collected from issues students encounter)
 

Project Submission

As with previous projects, you will upload each of the source code files (.cpp) you have written to Gradescope. Note that you are limited to 10 submissions on Gradescope, so ensure that you test your code thoroughly.

HashTable.cpp
LinkedList.cpp
BinarySearchTree.cpp
I will use the public methods of LinkedList.h, HashTable.h, and BinarySearchTree.h to grade your project.  You may not add any public methods to the header files but may add as many private functions/variables as you wish.

Please be sure to follow all specifications carefully.

Late Program:

No programs will be accepted.

Cheating Policy:

There is a zero tolerance policy on cheating in this course. You are expected to complete all programming assignments on your own. Collaboration with other students in the course is not permitted. You may discuss ideas or solutions in general terms with other students, but you must not exchange code. (Remember that you can get help from either instructor. This is not cheating, but is in fact encouraged.) We will examine your code carefully. Anyone caught cheating on a programming assignment or on an exam will receive an "F" in the course, and a referral to Judicial Procedures.
