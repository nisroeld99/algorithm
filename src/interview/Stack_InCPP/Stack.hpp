//
//  LinkedList.hpp
//  LinkedLIST
//
//  Created by 최형규 on 2016. 10. 30..
//  Copyright © 2016년 최형규. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0 

typedef int Sdata;
typedef struct Node{
    int Sdata;
    Node * next;
}Node ;

typedef struct Stack{
    Node *head;
    int size;
}Stack;

void StackInit(Stack * pstack);
int isEmpty(Stack * pstack);

void StackPush(Stack * pstack, Sdata data);
Sdata StackPop(Stack *pstack);
Sdata StackPeek(Stack *pstack);


#endif /* LinkedList_hpp */

