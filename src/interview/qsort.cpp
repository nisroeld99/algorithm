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
        int mid = partition(arr, first,last); // 한 피벗을 기준으로 좌우로 보내기
        quiksort(arr, first, mid-1);          // 왼쪽에서 다시 qsort
        quiksort(arr,mid+1, last);            // 오른쪽에서 다시 qsort
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
