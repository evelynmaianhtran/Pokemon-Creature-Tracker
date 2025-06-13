/*
* empty_collection_exception.h
* This class represents a custom exception that should be thrown when a collection is empty.
*/
#ifndef SENG1120_EMPTY_COLLECTION_H
#define SENG1120_EMPTY_COLLECTION_H

#include <exception>
#include <string>

class empty_collection_exception : public std::exception
{
public:
    const char* what() const noexcept override 
    { 
        return "Collection is empty."; 
    }
};

#endif
