/**
 *  @author: Abby Leary
 *    @date: 9/7/22
 *   @brief: Declaration and implementation of the node class, including constructors, mutators, and accessors
 *
 */

#include <iostream>
using namespace std;
#ifndef NODE_H
#define NODE_H

class node
{
public:
    /**
     *  Function:   node
     *              constuctor for the node; initializes the key and value to zero unless a value
     *              is passed, initializes the prev and next pointers to nullptr unless a value
     *              is passed.
     *
     *  @param k - new key
     *  @param v   - new value
     *  @param p   - new previous pointer
     *  @param n   - new next pointer
     */
    node(string k = "", string v = "", node *p = nullptr, node *n = nullptr)
    {
        key = k;
        value = v;
        prev = p;
        next = n;
    }

    /**
     *  Function:   setKey
     *              sets the new value of a key
     *
     *  @param newKey - new key
     */
    void setKey(string newKey)
    {
        key = newKey;
    }

    /**
     *  Function:   setValue
     *              sets the new value
     *
     *  @param newValue - new value
     */
    void setValue(string newValue)
    {
        value = newValue;
    }

    /**
     *  Function:   setPrev
     *              sets the previous pointer
     *
     *  @param p - new previous pointer
     */
    void setPrev(node *p) { prev = p; }

    /**
     *  Function:   setNext
     *              sets the next pointer
     *
     *  @param n - new next pointer
     */
    void setNext(node *n) { next = n; }

    /**
     *  Function:   getKey
     *              retrieves the key
     *
     *  @return - a string holding the key
     */
    string getKey() { return key; }

    /**
     *  Function:   getValue
     *              retrieves the value
     *
     *  @return - a string holding the value
     */
    string getValue() { return value; }

    /**
     *  Function:   getNext
     *              retrieves the next pointer
     *
     *  @return - a pointer to the next node
     */
    node *getNext() { return next; }

    /**
     *  Function:   getPrev
     *              retrieves the previous pointer
     *
     *  @return - a pointer to the previous node
     */
    node *getPrev() { return prev; }

private:
    string key;
    string value;
    node *next;
    node *prev;
};

#endif