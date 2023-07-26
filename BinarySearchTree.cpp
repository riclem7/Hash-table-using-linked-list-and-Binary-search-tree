// Ricardo Lemus
// class account number: cssc0329
// Student ID: 821687094
#include "BinarySearchTree.h"
using namespace BST_NS;


//For normal constructor:
//Pre conditions: nothing
//Post conditions: Creates a BST allowing any data type T


//Pre conditions: nothing
//Post conditions: Creates a new BST copy of the original BST
// copy ctor
template<class T>
    BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& other) {

                //copying the data using copyHelper
                root = copyHelper(other.root);
                //setting tree_size to new BST tree_size
                tree_size = other.tree_size;
    }

//Pre conditions: nothing
//Post conditions: Destroys the BST and cleans up the memory

// virtual dtor
template<class T>
    BinarySearchTree<T>::~BinarySearchTree() {
        //Using the makeEmpty() method and doing so until the node size is 0.
            if(tree_size != 0)
            {
                makeEmpty();
            }

    }

//Pre conditions: nothing
//Post conditions: Locates the location to add item and inserts it into the BST. We need to follow the BST rules
//which means we must have the smaller values on the left and the bigger values on the right

// insert an item to the tree
template<class T>
//Using the insertHelper to add to the BST then we increase the tree_size
    void BinarySearchTree<T>::insert(T item) {
    insertHelper(root,item);
    tree_size++;
    }

//Pre conditions: item is in the BST
//Post conditions: Item is removed from the BST. We use specific structures so the BST must maintain
//the structure

// remove an item from the tree
template<class T>
void BinarySearchTree<T>::remove(T item){
    //Using helper to decide how to remove a node from the BST
    removeHelper(root, item);

    //If we remove the last value then we will set the root to null
    if(tree_size == 0)
    {
        root = nullptr;
    }


}

//Pre conditions: nothing
//Post conditions: Searches through the tree finding the T item. If found, the method will return true.
//if not found, method returns false

// check if an item exists in the tree
template<class T>
bool BinarySearchTree<T>::inTree(T item) const{
    bool found = false;
    TreeNode<T>* node = root;

    //Keep searching until either we hit null or we find the item
    while(node != nullptr && !found)
    {
        //traverse through the BST and if we find the data then return true
        //if not found return false
        if(node->data == item)
            found = true;
        //If the numbers are bigger than we know we must look at the left side since values
        //will be smaller on left side
        else if (node->data > item)
        {
            node = node->leftLink;
        }
        //same as above but now we look right side if its bigger
        else //(node->data < item)
            node = node->rightLink;
    }
    return found;
}

//Pre conditions: nothing
//Post conditions: Current BST will be copied and the current BST will be cleaned up.
//A new BTS will be given which is a duplicate of the other one

// overloading assignment operator
template<class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T> other) {
    //Make the new BST empty to begin with and copy into a new BST
            makeEmpty();
            root = copyHelper(other.root);
            tree_size = other.tree_size;
            return *this;


}
//Pre conditions: nothing
//Post conditions: Will clean the BST and free up memory. BST will be empty in the end.

// empty the tree
template<class T>
void BinarySearchTree<T>::makeEmpty(){
    //Keep removing until the root is null
    while(root != nullptr){
        remove(root->data);
    }
}


//Pre conditions: A output stream will be printed in a certain order.
//Post conditions: The BST will be read in a ROOT-LEFT-RIGHT order and will be printed
//in that order to the terminal

// pre-order traversal (prints to stdout)
template<class T>
    void BinarySearchTree<T>::preOrderShow() const {
        //Using a helper and temp value to print out in a ROOT-LEFT-RIGHT format
        TreeNode<T>* temp = root;
        preOrderHelper(temp);
}

//Pre conditions: A output stream will be printed in a certain order.
//Post conditions: The BST will be read in a LEFT-ROOT-RIGHT order and will be printed
//in that order to the terminal

// in-order traversal (prints to stdout)
template<class T>
    void BinarySearchTree<T>::inOrderShow() const {
        //Printing in a LEFT-ROOT-RIGHT format
    TreeNode<T>* temp = root;
    inOrderHelper(temp);
    }

//Pre conditions: A output stream will be printed in a certain order.
//Post conditions: The BST will be read in a LEFT-RIGHT-ROOT order and will be printed
//in that order to the terminal

// post-order traversal (prints to stdout)
template<class T>
void BinarySearchTree<T>::postOrderShow() const{
    //Printing in a LEFT-RIGHT-ROOT format
    TreeNode<T>* temp = root;
    postOrderHelper(temp);
}

//Pre conditions: A int value will be returned of the size of the BST.
//Post conditions: The method will return a int value of how many nodes there are on the
//BST

// return size of tree
template<class T>
int BinarySearchTree<T>::size() const{
    return tree_size;
}

//Pre conditions: A int value will be returned of the height of the BST.
//Post conditions: The method will return a int of how "Tall" the BST is by counting the left and right
//subtrees edges only then seeing which one is the biggest and adding + 1 then returning the value.

// return height of tree
template<class T>
int BinarySearchTree<T>::height(){
    //Using height helper then returning the height
    return heightHelper(root);

}





//My own functions so I can use recursion on the BST.

template<class T>
TreeNode<T>* BinarySearchTree<T>::insertHelper(TreeNode<T>*& node, T item){
    //If tree is empty we make new node and make it the root
    if(node == NULL)
    {

        node = new TreeNode<T> (item, nullptr, nullptr);

    }
    //Else we must put it at the right or left side depending on how big the value is
    else if(node->data > item)
    {

        node->leftLink = insertHelper(node->leftLink, item);

    }
    else
    {

        node->rightLink = insertHelper(node->rightLink, item);
    }

    return node;
}


template<class T>
void BinarySearchTree<T>::inOrderHelper(TreeNode<T>* node) const{
    if(node != nullptr)
    {
        //LEFT-ROOT-RIGHT
        inOrderHelper(node->leftLink);
        std::cout << node->data << " ";
        inOrderHelper(node->rightLink);
    }
}

template<class T>
TreeNode<T>* BinarySearchTree<T>::removeHelper(TreeNode<T>*& node, T item){

    //Do nothing if tree is empty
    if(node == NULL)
    {

        return node;

    }
    //Finding the data. We must traverse left or right depending on how big the data is
    else if(node->data > item)
    {

        node->leftLink = removeHelper(node->leftLink, item);

    }
    else if (node->data < item)
    {

        node->rightLink = removeHelper(node->rightLink, item);
    }

    //leaf node with 0 or 1 child
    else {
        if(node->leftLink == nullptr && node->rightLink == nullptr)
        {

            delete node;
            tree_size--;
            return nullptr;
        }
        //If left child is null
        else if (node->leftLink == nullptr)
        {
            TreeNode<T>* temp = node;
            node = node->rightLink;
            delete temp;
            tree_size--;
            return node;
        }
        //if right child is null
        else if (node->rightLink == nullptr)
        {
            TreeNode<T>* temp = node;
            node = node->leftLink;
            delete temp;
            tree_size--;
            return node;
        }
        //2 children
        else
        {
            //finding the next highest element in right subtree
            //replacing it with the inorder successor then deleting the duplicated node
            TreeNode<T>* temp = node->rightLink;
            while(temp != nullptr && temp->leftLink != nullptr)
            {
                temp = temp->leftLink;
            }
            node->data = temp->data;
            node->rightLink = removeHelper(node->rightLink, temp->data);
        }

    }

    return node;
}

template<class T>
void BinarySearchTree<T>::preOrderHelper(TreeNode<T>* node) const{
    if(node != nullptr)
    {
        //ROOT-LEFT-RIGHT
        std::cout << node->data << " ";
        preOrderHelper(node->leftLink);
        preOrderHelper(node->rightLink);
    }
}

template<class T>
void BinarySearchTree<T>::postOrderHelper(TreeNode<T>* node) const{
    if(node != nullptr)
    {
        //LEFT-RIGHT-ROOT
        postOrderHelper(node->leftLink);
        postOrderHelper(node->rightLink);
        std::cout << node->data << " ";
    }
}

template<class T>
int BinarySearchTree<T>::heightHelper(TreeNode<T>* node) {
    //if empty then high is 0...
    if(node == nullptr){
        return 0;
    }
    //Recursion
    int leftHeight = heightHelper(node->leftLink);
    int rightHeight = heightHelper(node->rightLink);

    //Finding the edges only then returning the int with +1 because we must add the root too
    if(leftHeight > rightHeight)
    {
        return leftHeight +1;
    }
    else
        return rightHeight +1;

}

template<class T>
TreeNode<T>* BinarySearchTree<T>::copyHelper(TreeNode<T>* node){
    //Copying the BST to a new BST then returning it
    if(node != nullptr){
        TreeNode<T>* newNode = new TreeNode<T>(node->data, copyHelper(node->leftLink), copyHelper(node->rightLink));
        return newNode;
    }
    return nullptr;
}