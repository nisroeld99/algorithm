/*
 * 0-1knapsack.cpp
 *
 */
//
//  main.cpp
//  icpc
//
//  Created by 최형규 on 2016. 10. 31..
//  Copyright © 2016년 Nisroeld. All rights reserved.
//
/*
 4 5
 5 1
 7 2
 8 3
 9 4
 

 */
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
int knap[100];
int weight[100];
int d[100][1000];
int main() {
    int n , c;
    cin >> n >> c;
    for (int i = 1; i<=n; i++){
        scanf("%d%d",&knap[i],&weight[i] ) ;
    }
    
    for (int i =0 ; i<=c;i++){
        if (  i >= weight[1] )
            d[1][i]=knap[1];
    }
    
    for (int i =2 ; i<=n; i++){
        for (int j= 0 ; j<=c; j++){
            if ( j-weight[i] < 0 ){
                d[i][j ] = d[i-1][j];
            }else {
                d[i][j] = max ( d[i-1][j], knap[i] + d[i-1][j-weight[i]] );
            }
        }
    }
    for (int i = 1 ; i<=n; i++){
        for (int j= 0 ; j<=c ;j++){
            printf("%d ",d[i][j]);
        }printf("\n");
    }
    cout << d[4][5] << endl;
}
