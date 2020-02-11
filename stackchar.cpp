//
//  StackChar.cpp
//  SigFigSimple
//
//  Created by Nicholas Cooke on 7/19/17.
//  Copyright © 2017 Nicholas Cooke. All rights reserved.
//

#include "stackchar.h"
#include <iostream>
#include <cctype>

using namespace std;

DynCharStack::~DynCharStack()
{
    StackNode * nptr = nullptr;
    StackNode * nextNode = nullptr;
    nptr = top;
    
    while (nptr)
    {
        nextNode = nptr->next;
        delete nptr;
        nptr = nextNode;
    }
}
void DynCharStack::push(char x)
{
    StackNode * newNode = nullptr;
    
    newNode = new StackNode;
    newNode->value = x;
    
    if(isEmpty())
    {
        top = newNode;
        newNode->next = nullptr;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}
void DynCharStack::pop(char &x)
{
    StackNode * nptr = nullptr;
    
    if(isEmpty())
        cout << "Stack's Empty.";
    else
    {
        x = top->value;
        nptr = top->next;
        delete top;
        top = nptr;
    }
}

bool DynCharStack::isEmpty()
{
    if (!top)
        return true;
    else
        return false;
}

int DynCharStack::stackSize() const
{
    // so i need to cycle through list and count++ for each element
    int count = 0;
    StackNode * nptr = top;
    
    if (!top)
        return 0;
    else
    {
        while (nptr != nullptr)
        {
            if (isdigit(nptr->value))
                count++;
            
            nptr = nptr->next;
        }
        return count;
    }
    return -1;
}
