// Ricardo Lemus
// class account number: cssc0329
// Student ID: 821687094
// BinarySearchTree.h:	Header file for BinaryBinarySearchTree.cpp
// The only way to insert data in a tree is with the insert function, thus
// satisfying the BST rule giving it a well behaved ordering to the type T.

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream> // for std::cout

namespace BST_NS
{
	template<class T>
	class BinarySearchTree; //forward declaration

	template<class T>
	class TreeNode {
		public:
			TreeNode( ) : data(NULL), leftLink(NULL), rightLink(NULL) {}
			TreeNode(T theData, TreeNode<T>* left, TreeNode<T>* right)
				: data(theData), leftLink(left), rightLink(right) {}
			friend class BinarySearchTree<T>;
		private:
			T data;
			TreeNode<T>* leftLink;
			TreeNode<T>* rightLink;
	};


	// supply the pre and post conditions for each method
	template<class T>
	class BinarySearchTree {
		private:
			TreeNode<T> *root;
			int tree_size;
		public:
			// default ctor
			BinarySearchTree() : root(NULL), tree_size(0) {}
			// copy ctor
			BinarySearchTree(const BinarySearchTree& other);
			// virtual dtor
			virtual ~BinarySearchTree();
			// insert an item to the tree
			void insert(T item);
			// remove an item from the tree
			void remove(T item);
			// check if an item exists in the tree
			bool inTree(T item) const;
			// overloading assignment operator
			BinarySearchTree& operator=(const BinarySearchTree other);
			// empty the tree
			void makeEmpty();
			// pre-order traversal (prints to stdout)
			void preOrderShow() const;
			// in-order traversal (prints to stdout)
			void inOrderShow() const;
			// post-order traversal (prints to stdout)
			void postOrderShow() const;
			// return size of tree
			int size() const;
			// return height of tree
			int height();

            //Private helper functions
    private:
        //Insert helper

            TreeNode<T>* insertHelper(TreeNode<T>*& node, T item);
            void inOrderHelper(TreeNode<T>* node) const;
            TreeNode<T>* removeHelper(TreeNode<T>*& node, T item);
            void preOrderHelper(TreeNode<T>* node) const;
            void postOrderHelper(TreeNode<T>* node) const;
            int heightHelper(TreeNode<T>* node);
            TreeNode<T>* copyHelper(TreeNode<T>* node);

	};


} // BST_NS

#endif
