

#include "HashTable.h"
using namespace HashTableNS;

HashTable::HashTable() {
    //initializing a empty hashtable
    for(int i=0; i < SIZE; i++){
        hashArray[i] = nullptr;
    }
}


HashTable::~HashTable() {
    //destroying the hash table
    for(int i=0; i < SIZE; i++)
    {
        //deleting each element one by one using our function from linked list
        while(hashArray[i])
            LinkedListNS::deleteFirstNode(hashArray[i]);
    }

    //deleting the container??
    //delete[] *hashArray;

}

bool HashTable::containsString(std::string target) const {
    bool found = false;
    int index = computeHash(target);
    //returns false as its nullptr
    if(hashArray[index] == nullptr){
        return found;
    }
    else {
        //We use our function search from linked list
        //Node<string>* temp = hashArray[index];
        Node<string>* temp = LinkedListNS::search(hashArray[index], target);
        //if we found valid node then we return true
        if(temp)
        {
            found = true;
        }
    }
    //otherwise we return false
    return found;
}

void HashTable::put(std::string s) {
    //finding where to put it
    int index = computeHash(s);

    if(hashArray[index] == nullptr)
    {
        hashArray[index] = new Node<string>(s, nullptr);
    }
    //if index is busy then we save previous data and add new data
    else {
        Node<string>* temp = hashArray[index];
        //We use our linked list functions
        LinkedListNS::headInsert(temp, s);
    }
}

int HashTable::computeHash(std::string s) {
    int total =0;
    //finding the hash value for a string
    for (int i=0; i < s.length(); i++)
    {
        total = total + int(s[i]);
    }
    //returning the bucket where it is supposed to go at
    return total % SIZE;

}




