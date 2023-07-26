// Ricardo Lemus
// class account number: cssc0329
// Student ID: 821687094
#include "LinkedList.h"



template<class T>
    void LinkedListNS::headInsert(Node<T>*& head, const T& theData){
        if(head == nullptr)
        {
            head = new Node<T>(theData, nullptr);
        }
        else
        {
            //making a temp node with previous head then we insert the new node data at the head
            Node<T> *temp = new Node<T>(head->getData(), head->getLink());
            head->setLink(temp);
            head->setData(theData);
        }

}


template<class T>
void LinkedListNS::insert(Node<T>* afterMe, const T& theData){
    if(afterMe) {
    Node<T> *newNode = new Node<T>(theData, nullptr);
        //Check afterMe->getLink is null
        //If it is null then its end of the list. We set Afterme->getlink to newNode with new data
        if (afterMe->getLink() == nullptr) {
            afterMe->setLink(newNode);
        }
            //If not null, we have make temp variable of Afterme->getlink. Set Afterme-> getlink = new node with the new data
            //newNode = getlink (temp)
        else {
            Node<T> *temp = new Node<T>(afterMe->getLink()->getData(), afterMe->getLink()->getLink());
            afterMe->setLink(newNode);
            newNode->setLink(temp);
        }
    }
}

template<class T>
    void LinkedListNS::deleteNode(Node<T>* before){
        if(before){
        //Make nodeTodelete variable before->getLink then temp variable = nodeToDelete->getLink
        Node <T>* nodeToDelete = before->getLink();
        Node<T>* temp = nodeToDelete->getLink();
        //setting node before to node ahead of nodeToDelete to not lose the list
        before->setLink(temp);
        delete nodeToDelete;
        }

}

template<class T>
    void LinkedListNS::deleteFirstNode(Node<T>*& head){
        if(head){
    //If our only node is the head then we simply delete the head
    if(head->getLink() == nullptr){
        Node<T>* temp = head;
        head = nullptr;
        delete temp;
    }
    else {
        //If there are more nodes behind the head then we must do a little more work
        //We set node behind head to head value
        head->setData(head->getLink()->getData());
        //We delete node before head as thats we wanted to do. We have replaced head with previous node.
        LinkedListNS::deleteNode(head);
    }
        }
}

template<class T>
    LinkedListNS::Node<T>* LinkedListNS::search(LinkedListNS::Node<T>* head, const T& target){
    //If empty then return the head aka nullptr
    if(head == nullptr)
        return head;
    LinkedListNS::Node<T>* temp = head;
    while(temp){
        if(temp->getData() == target)
        {
            //if found we return the node
            return temp;
        }
        //traverse through the linked list
        temp = temp->getLink();
    }
    //if not found we return nullptr as specified
    return nullptr;

}