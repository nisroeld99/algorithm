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

typedef int LData;

typedef struct Node {
    LData data;
    struct Node * next ;
}Node;

typedef struct List{
    Node * pre;
    Node * cur;
    Node * head;
    
    int size;
}List;

void ListInit (List * plist);
void ListAdd( List * plist ,LData data);


bool Remove_Data_From_List(List * plist, int data);

int LNext (List *plist , LData *pdata);
int LFirst ( List * plist, LData *pdata);

LData LRemove ( List *plist );

int LCount (List *plist);

void PrintAllList(List*plist ) ;



#endif /* LinkedList_hpp */
