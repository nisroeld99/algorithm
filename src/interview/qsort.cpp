/*
 *  qsort   
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
 
using namespace std;
void quiksort(int arr[] , int first,int last );
int partition(int arr[], int first,int last);
 
 
int main(int argc, const char * argv[]) {
    int arr[1111] ;
    int n ;
     
    scanf("%d",&n);
    for (int i =0  ; i<n; i++){
        scanf("%d",&arr[i]);
    }
     
    quiksort(arr,0, n-1);
    for (int i = 0 ; i<n;i++)
        printf("%d\n",arr[i]);
     
}
void quiksort(int arr[] , int first, int last ){
    if ( first < last) {
        int mid = partition(arr, first,last);
        quiksort(arr, first, mid-1);
        quiksort(arr,mid+1, last);
         
    }
     
}
int partition(int arr[], int first,int last){
    int pivot = arr[first];
    int l=first ,r=last+1 ;
    do {
        do {
            l++;
        }while ( arr[l] < pivot && l < last);
        do {
            r--;
        }while (arr[r] > pivot && r >first);
        if ( l < r ) swap(arr[l] , arr[r]);
    }while ( l<r);
     
    swap ( arr[first] , arr[r]);
     
    return r;
}
