/*
 *  mergeSort   
 */
//
//  main.c
//  LinkedLIST
//
//  Created by 최형규 on 2016. 10. 30..
//  Copyright © 2016년 최형규. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void mergesort(int arr[] , int first, int last );
void merge(int arr[], int first,int mid ,int last);


int main(int argc, const char * argv[]) {
    int arr[5] = {100100,-10,-1,3,4};
    mergesort(arr,0, 4);
    for (int i = 0 ; i<5;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void mergesort(int arr[] , int first, int last ){
    if (first<last){  //분할할 것이 존재하는 한
        int mid = (first + last)/2;
        mergesort(arr,first,mid);
        mergesort(arr,mid+1,last);
        merge (arr,first,mid+1,last);
    }
}
void merge(int arr[], int first ,int mid, int last){
    int *temp = new int[last-first+1];
    
    int f =first;
    int m = mid;
    
    int i=0 ;
    while(f <= mid-1 && m <= last ){
        if ( arr[f] < arr[m])
            temp[i++] = arr[f++];
        else
            temp [i++] = arr[m++];
    }
    
    
    while (  m <= last){
          temp[i++] = arr[m++];
    }
    
    
    while ( f<=mid)
        temp [i++] = arr[f++];
    
    
    for (int k = 0 ; k< i-1 ; )
        arr[first++] = temp [k++] ;
    
    free(temp);
}
