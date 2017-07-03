#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;



int a[22222];


int solve (int left, int right ){
    if ( left == right ) return a[left] ;
    
    int mid = (left+right)/2 ;
    
    int ret = max ( solve(left , mid) , solve ( mid+1, right));
    
    int lo = mid , hi = mid +1 ;
    int height = min (a[lo] , a[hi] );
    
    ret = max ( ret , height*2);
    
    while ( left < lo || hi <right ){
        if ( hi <right && (lo == left || a[lo-1] < a[hi+1])){
            hi ++ ;
            height = min (height,  a[hi]);
        }
        else {
            lo --;
            height = min ( height, a[lo]);
        }
        
        ret = max ( height * (hi-lo+1 ) , ret );
        
    }
    
    
    
    
    return ret;
}


int main(){
    
    //freopen("input.txt", "r", stdin);
    
    
    int tc;
    cin >> tc;
    while (tc--){
        int n ;
        scanf("%d",&n);
        for (int i = 1; i<=n ; i++)
            scanf("%d", &a[i]);
        
        
        cout << solve ( 1, n )<< endl; ;
        
    }
}

