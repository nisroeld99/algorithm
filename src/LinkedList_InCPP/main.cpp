//
//  main.c
//  LinkedLIST
//
//  Created by 최형규 on 2016. 10. 30..
//  Copyright © 2016년 최형규. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.hpp"
int main(int argc, const char * argv[]) {
    List list;
    
    ListInit( &list);
    ListAdd( &list, 10);
    ListAdd ( &list , 20);
    ListAdd ( &list , 30);
    ListAdd ( &list , 40);
    
   
    
    Remove_Data_From_List(&list, 20);
    PrintAllList(&list);
    
    return 0 ;
}
