#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
vector<vector<int> > button({
    vector<int>( { 0, 1, 2 }),
    vector<int>( { 3, 7, 9, 11 }),
    vector<int>( { 4, 10, 14, 15 }),
    vector<int>( { 0, 4, 5, 6, 7 }),
    vector<int>( { 6, 7, 8, 10, 12 }),
    vector<int>( { 0, 2, 14, 15 }),
    vector<int>( { 3, 14, 15 }),
    vector<int>( { 4, 5, 7, 14, 15 }),
    vector<int>( { 1, 2, 3, 4, 5 }),
    vector<int>( { 3, 4, 5, 9, 13 })
});

int clocks[16] ={};

void jd(int  buttons){
    for (int i = 0 ; i< button[buttons].size() ;i++){
        int & now = clocks [button[buttons][i]];
        now +=3;
        if (now >12)
            now%=12;
    }
}

bool check(){
    for (int i = 0 ; i<16; i++)
        if ( clocks[i] != 12 )
            return false;
    return true ;
}
const int inf =41;
int ans = inf ;
int solve (int swch ){
    
    if ( swch == 10 ) {
        if ( check() == false ){
            return inf ;
        }
        else return 0;
    }
    
    int ret = inf ;
    
    for (int i= 0 ; i<4; i++){
        ret = min ( ret ,i+ solve(swch+1)) ;
        jd(swch);
    }
    
    
    return ret ;
    
}


int main(){
    //freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    
    while (tc--){
        ans = inf ;
        /* 입력 */
        for (int i = 0 ; i<16; i++)
            cin >> clocks[i] ;
        
        
        ans = solve (0 );
        
        if ( ans == inf )ans = -1 ;
        cout << ans << endl ;
        
        
    }
    

}
