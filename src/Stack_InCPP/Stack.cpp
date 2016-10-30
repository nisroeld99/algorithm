//
//  main.c
//  LinkedLIST
//
//  Created by 최형규 on 2016. 10. 30..
//  Copyright © 2016년 최형규. All rights reserved.
//

#include <stdio.h>
#include "Stack.hpp"
int main(int argc, const char * argv[]) {
    Stack stack;
    StackInit(&stack);
    
    StackPush(&stack, 10);
    StackPush(&stack, 20);
    StackPush(&stack, 30);
    StackPush(&stack, 40);
    StackPush(&stack, 50);
    
    while ( !isEmpty(&stack)){
        printf("%d\n", StackPop(&stack));
    }
    
    return 0 ;
}

