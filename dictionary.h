#include <iostream>
/**
 *  @author: Abby Leary
 *    @date: 9/7/22
 *   @brief: Declaration of the dictionary class
 *
 */

#include <vector>
#include "node.h"
using namespace std;
#ifndef DICTIONARY_H
#define DICTIONARY_H

class Dictionary
{
public:
    /**
     *  Function:   Dictionary
     *              default constructor for dictionary class
     *
     */
    Dictionary();

    /**
     *  Function:   Dictionary
     *              dictionary class copy constructor
     *
     *  @param other - dictionary class being copied
     */
    Dictionary(Dictionary &other);

    /**
     *  Function:   ~Dictionary
     *              dictionary class deconstructor
     *
     */
    ~Dictionary();

    /**
     *  Function:   operator=
     *              dictionary class assignment operator
     *
     *  @param other - dictionary class being copied
     *  @return - a copy of the original dictionary
     */
    Dictionary operator=(Dictionary &other);

    /**
     *  Function:   get
     *              retrieves the value corresponding to a key, otherwise
     *              returns "NOT_FOUND"
     *
     *  @param key - key being searched for
     *  @return - the value corresponding to a key, otherwise returns "NOT_FOUND"
     */
    string get(string key);

    /**
     *  Function:   put
     *              creates a new node in the list with the new key and value,
     *              places the node in alphabetical order by key
     *
     *  @param key - new key
     *  @param value - new value
     */
    void put(string key, string value);

    /**
     *  Function:   keys
     *              creates a vector of all of the keys in order
     *
     *  @return - a vector containing all keys in the dictionary in alphabetical order
     */
    vector<string> keys();

    /**
     *  Function:   values
     *              creates a vector of all of the values in order
     *
     *  @return - a vector containing all values in the dictionary in alphabetical order
     */
    vector<string> values();

    /**
     *  Function:   hasKey
     *              checks if a key already exists in the dictionary
     *
     *  @param key - key being searched for
     *  @return - true if the key exists, false if not
     */
    bool hasKey(string key);

    /**
     *  Function:   hasValue
     *              checks if a value already exists in the dictionary
     *
     *  @param value - value being searched for
     *  @return - true if the value exists, false if not
     */
    bool hasValue(string value);

    /**
     *  Function:   size
     *              checks the size of the dictionary
     *
     *  @return - the amount of entries in the dictionary
     */
    int size();

    /**
     *  Function:   removeKey
     *              removes an entry in the dictionary with a corresponding key
     *
     *  @param key - key corresponding to entry being removed
     */
    void removeKey(string key);

    /**
     *  Function:   removeValues
     *              removes all entries in the dictionary with a corresponding value
     *
     *  @param key - value corresponding to entries being removed
     */
    void removeValues(string value);

private:
    node *head;
    node *tail;
};

/**
 *  Function:   caps
 *              converts a string to all capital letters
 *
 *  @param word - word to be converted to capitals
 *  @return - the same word passed in capital letters
 */
string caps(string word);

#endif