//
//  LinkedList.cpp
//  LinkedLIST
//
//  Created by 최형규 on 2016. 10. 30..
//  Copyright © 2016년 최형규. All rights reserved.
//

#include "LinkedList.hpp"



bool Remove_Data_From_List(List * plist, int pdata){
    int data;
    if ( LFirst(plist , &data) ){
        if (pdata == data){
            LRemove(plist);
            return true ;
        }
    }
    while ( LNext(plist, &data) ) {
        if (pdata == data){
            LRemove( plist);
            return true ;
        }
    }
    
    return false; 
    

}
void ListInit (List * plist){
    Node * newNode = (Node * )malloc(sizeof(Node));
    plist -> size = 0 ;
    plist -> head = newNode;
}
void ListAdd( List * plist ,LData pdata){//머리 추가 linked List
    Node * newNode = (Node * )malloc(sizeof(Node));
    newNode -> data = pdata;
    
    newNode -> next = plist->head ->next ;
    plist -> head -> next = newNode;
}


int LNext (List *plist , LData *pdata){
    if (plist->cur->next == NULL)
        return false ;
    
    plist -> pre = plist -> cur;
    plist->cur = plist->cur->next;
    
    *pdata = plist ->cur -> data;
    return true ;
}
int LFirst ( List * plist, LData * pdata){
    if ( plist -> head -> next ==NULL)
        return false;
    
    plist ->pre = plist ->head;
    plist ->cur = plist->head ->next ;
    
    *pdata = plist ->cur ->data;
    
    return true ;
}

LData LRemove ( List *plist ){
    Node * removed_Node = plist -> cur;
    LData rdata = removed_Node ->data;
    
    plist -> pre -> next = plist -> cur -> next;
    plist -> cur = plist -> pre;
    
    free (removed_Node);
    plist->size -- ;
    return rdata ;
}

int LCount (List *plist){
    return plist -> size ;
}

void PrintAllList(List*plist ){
    if ( plist -> head -> next == NULL){
        printf("List is Empty! \n");
        return;
    }
    int data ;
    if ( LFirst(plist, &data )){
        printf("%d ", data);
    }

    while ( LNext(plist, &data)){
        printf("%d ", data);
    }
    printf("\n");

}