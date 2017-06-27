#include <iostream>
#include <cstring>
using namespace std ;


bool hasFriend[11]; // 친구 유무
bool isFriend[11][11];

int ans = 0 ;


bool check_ (int num ){
    for (int i = 0 ; i<num ; i ++){
        if ( hasFriend[i] == false ){
            return false;
        }
    }
    return true ;
}


void solve( int numOfFri){
    if (check_(numOfFri)){
        ans ++ ;
        return ;
    }
    
    int first = -1;
    for (int i = 0 ; i<numOfFri ; i++){
        if ( !hasFriend[i] ){
            first = i ;
            break;
        }
    }
    
    if ( first == -1) return ;
    
    for (int i = first+1 ; i< numOfFri ;i++){
        if ( hasFriend[i] ) continue;
        if ( isFriend[first][i] == false ) continue;
        hasFriend [i] = hasFriend[first] = true;
        solve ( numOfFri);
        hasFriend [i] = hasFriend[first] = false ;
    }
    
}


int main(){
    freopen("input.txt", "r", stdin);
    
    int tc;
    cin >> tc;
    while (tc-- ){
        memset (hasFriend, false , sizeof(hasFriend));
        memset (isFriend, false , sizeof(isFriend));
        ans =  0 ;
        
        int  n , m ;
        scanf("%d%d",&n,&m);
        for (int i = 0 ; i<m ; i++){
            int first,second;
            scanf("%d%d",&first, & second ) ;
            isFriend[first] [second] = true;
            isFriend[second] [first] = true;
        }
        
        solve(n);
        cout << ans << endl;
    }
}

