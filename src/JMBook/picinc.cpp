/*
 * picinc.cpp
 *
 *  코드 오류 잡아야함.  1  2 5 
 *
 */


#include <stack>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool taken[11];
bool areFriends[11][11] ;
int n ,m;


int countParings (){
    
    int firstFree = -1 ;
    for (int i = 0 ; i< n ; i++){
        if ( !taken[i ]){
            firstFree= i;
            break ;
        }
    }
    
    if (firstFree ==-1 ){
        
        return 1 ;
    }
    
    int ret = 0 ;
    for (int j= firstFree+1 ; j<n ;j++){
        if (!taken [j]  && areFriends [firstFree][j] ){
            taken[firstFree] =taken[j] = true ;
            ret += countParings() ;
            taken[firstFree] =taken[j] = false ;
        }
    }
    return ret ;
}




int main() {
    freopen( "input.txt", "r",stdin);
    int tc ;
    cin >> tc;
    while (tc--){
        memset ( taken ,false, sizeof ( taken ) );
        memset ( areFriends , false ,sizeof ( areFriends ) );
        
        scanf("%d%d",&n,&m);
        for (int i = 0 ;i < m; i++){
            int first, second;
            scanf("%d%d",&first , & second );
            areFriends [first][second] = areFriends[second][first] = true ;
        }
        cout << countParings() << endl ;
    }
    
    
    
    
}


