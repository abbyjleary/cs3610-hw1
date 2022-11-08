/**
 *  @author: Abby Leary
 *    @date: 9/7/22
 *   @brief: Implementation of the dictionary class; includes functions to add, remove, etc.
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include "node.h"
#include "dictionary.h"

using namespace std;

Dictionary::Dictionary()
{
    // initializes the head and tail to the null pointer
    head = tail = nullptr;
}

Dictionary::Dictionary(Dictionary &other)
{
    if (head == other.head)
    {
        // if the lists are the same, return
        return;
    }
    if (other.head == nullptr)
    {
        // if the list being copied is null, set the new list to null
        head = tail = nullptr;
    }
    else
    {
        node *src;
        node *dest;

        // copy nodes from old list to new list
        head = new node(other.head->getKey(), other.head->getValue());
        src = other.head->getNext();
        dest = tail = head;
        while (src != nullptr)
        {
            dest->setNext(new node(src->getKey(), src->getValue(), head));
            src = src->getNext();
            tail = dest;
            dest = dest->getNext();
        }
    }
}

Dictionary::~Dictionary()
{
    node *cursor;
    while (head != nullptr)
    {
        // delete all nodes in the list
        cursor = head;
        head = head->getNext();
        delete cursor;
    }
}

Dictionary Dictionary::operator=(Dictionary &other)
{
    if (this == &other)
    {
        // if the lists are already the same, return
        return *this;
    }
    node *cursor;
    while (head != nullptr)
    {
        // go through the list and delete what already exists
        cursor = head;
        head = head->getNext();
        delete cursor;
    }
    node *src;
    node *dest;

    // replace the list with nodes from the other list
    head = new node(other.head->getKey(), other.head->getValue());
    src = other.head->getNext();
    dest = tail = head;
    while (src != nullptr)
    {
        dest->setNext(new node(src->getKey(), src->getValue(), head));
        src = src->getNext();
        tail = dest;
        dest = dest->getNext();
    }
}

string Dictionary::get(string key)
{
    node *cursor = head;

    // go through the list
    while (cursor != nullptr)
    {
        if (caps(cursor->getKey()) == caps(key))
        {
            // if the list contains the key, return the value
            return cursor->getValue();
        }

        cursor = cursor->getNext();
    }

    // if the key is not in the list, return "NOT_FOUND"
    return "NOT_FOUND";
}

void Dictionary::put(string key, string value)
{
    // if the list is empty
    if (head == nullptr)
    {
        // add node and mark as both head and tail
        head = new node(key, value);
        tail = head;
        return;
    }

    // if there is one thing in the list
    else if (head->getNext() == nullptr)
    {

        // if the new key goes before the existing key
        if (caps(key) < caps(head->getKey()))
        {
            // create the new node as the head
            node *tmp = head;
            head = new node(key, value, nullptr, tmp);
            head->getNext()->setPrev(head);
            return;
        }

        // if the new key goes after the existing key
        else if (caps(key) > caps(head->getKey()))
        {
            // create the new node as the tail
            head->setNext(new node(key, value, head, nullptr));
            tail = head->getNext();
            return;
        }
    }

    // if there are multiple items in the list
    else
    {

        node *cursor = head;

        // moving through the list
        while (cursor != nullptr)
        {
            // if the key already exists
            if (caps(cursor->getKey()) == caps(key))
            {
                // change the value
                cursor->setValue(value);
                return;
            }

            // if it goes at the beginning
            else if (caps(head->getKey()) > caps(key))
            {
                // create the new node as the head
                node *tmp = head;
                head->setPrev(new node(key, value, nullptr, tmp));
                head = head->getPrev();
                return;
            }

            // if it goes at the end
            else if (caps(tail->getKey()) < caps(key))
            {
                // create the new node as the tail
                node *tmp = tail;
                tail->setNext(new node(key, value, tmp, nullptr));
                tail = tail->getNext();
                return;
            }

            // if the node belongs after the cursor
            else if (caps(key) > caps(cursor->getKey()) && caps(key) < caps(cursor->getNext()->getKey()))
            {
                // place the new node between the cursor and the next node
                node *tmp = cursor->getNext();
                cursor->setNext(new node(key, value, cursor, cursor->getNext()));
                tmp->setPrev(cursor->getNext());
                return;
            }

            cursor = cursor->getNext();
        }
    }
}

vector<string> Dictionary::keys()
{
    vector<string> keys;
    node *cursor = head;

    // walk through the list
    while (cursor != nullptr)
    {
        // add each key to the vector
        keys.push_back(cursor->getKey());
        cursor = cursor->getNext();
    }

    return keys;
}

vector<string> Dictionary::values()
{

    vector<string> values;
    node *cursor = head;

    // walk through the list
    while (cursor != nullptr)
    {
        // add each value to the vector
        values.push_back(cursor->getValue());
        cursor = cursor->getNext();
    }

    return values;
}

bool Dictionary::hasKey(string key)
{
    node *cursor = head;

    // walk through the list
    while (cursor != nullptr)
    {
        // if the key is found, return true
        if (caps(key) == caps(cursor->getKey()))
        {
            return true;
        }
        cursor = cursor->getNext();
    }

    // otherwise, return false
    return false;
}

bool Dictionary::hasValue(string value)
{
    node *cursor = head;

    // walk through the list
    while (cursor != nullptr)
    {
        // if the value is found, return true
        if (caps(value) == caps(cursor->getValue()))
        {
            return true;
        }
        cursor = cursor->getNext();
    }

    // otherwise, return false
    return false;
}

int Dictionary::size()
{
    node *cursor = head;
    int size = 0;

    while (cursor != nullptr)
    {
        // add to the size for every node
        size++;
        cursor = cursor->getNext();
    }

    return size;
}

void Dictionary::removeKey(string key)
{
    node *tmp = head;

    // if the key exists in the list
    if (hasKey(key))
    {

        // if it is the only item in the list
        if (size() == 1)
        {
            // remove the item and set head and tail to nullptr
            delete head;
            head = tail = nullptr;
        }

        while (caps(key) != caps(tmp->getKey()))
        {
            // go through the list until the key is found
            tmp = tmp->getNext();
        }

        // if the node being removed is the first one
        if (tmp == head)
        {
            // set the next node as the head
            head = head->getNext();
            delete tmp;
            head->setPrev(nullptr);
        }

        // if the node being removed is the last one
        if (tmp == tail)
        {
            // set the node as tail
            tail = tail->getPrev();
            delete tmp;
            tail->setNext(nullptr);
        }

        else
        {
            // otherwise, move pointers and delete node
            tmp->getPrev()->setNext(tmp->getNext());
            tmp->getNext()->setPrev(tmp->getPrev());
            delete tmp;
        }
    }
}

void Dictionary::removeValues(string value)
{
    node *tmp = head;

    // if the value exists in the list
    if (hasValue(value))
    {
        // if it's the only node in the list
        if (size() == 1)
        {
            delete head;
            head = tail = nullptr;
        }

        // if the node is at the beginning of the list
        while (caps(value) == caps(head->getValue()))
        {
            // remove the head and move head to the next node
            head = head->getNext();
            delete head->getPrev();
            head->setPrev(nullptr);
        }

        // if the node is at the end of the list
        while (caps(value) == caps(tail->getValue()))
        {
            // remove the tail and mode tail to the previous node
            tail = tail->getPrev();
            delete tail->getNext();
            tail->setNext(nullptr);
        }

        // walk through the list
        while (tmp != nullptr)
        {
            // if the value is found
            if (caps(tmp->getValue()) == caps(value))
            {
                // move pointers and delete node
                tmp->getPrev()->setNext(tmp->getNext());
                tmp->getNext()->setPrev(tmp->getPrev());
                delete tmp;
            }

            tmp = tmp->getNext();
        }
    }
}

string caps(string word)
{
    // go through the word letter by letter
    for (int i = 0; i < word.length(); i++)
    {
        // convert every letter to uppercase
        word[i] = toupper(word[i]);
    }

    return word;
}