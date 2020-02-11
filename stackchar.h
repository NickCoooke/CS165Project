//
//  StackChar.hpp
//  SigFigSimple
//
//  Created by Nicholas Cooke on 7/19/17.
//  Copyright © 2017 Nicholas Cooke. All rights reserved.
//

#ifndef StackChar_hpp
#define StackChar_hpp

#include <stdio.h>
class DynCharStack
{
private:
    struct StackNode
    {
        char value;
        StackNode * next;
    };
    StackNode *top;
    
public:
    DynCharStack() { top = nullptr; }
    ~DynCharStack();
    
    void push(char);
    void pop(char &);
    bool isEmpty();
    int stackSize() const;
};

#endif /* StackChar_hpp */
