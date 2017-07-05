#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int map[101][101];
int cache[101][101];
int dy[2] = {0,1}, dx[2] = {1,0};
int n ;
bool inRange(int ypos ,int xpos ){
    if ( ypos < 1 || xpos < 1 || ypos > n || xpos > n )return false;
    return true ;
}
int solve(int ypos, int xpos ){
    
    
    if (cache[ypos][xpos]!=-1 )
        return cache[ypos][xpos];
    
    int & ret = cache[ypos][xpos];
    
    
    ret = 0 ;
    if ( ypos == n && xpos == n){
        return ret = 1;
    }
    

    for (int i = 0 ; i<2; i++){
        int ny = ypos +dy[i]*map[ypos][xpos];
        int nx = xpos +dx[i]*map[ypos][xpos];
        if ( !inRange(ny,nx)) continue;
        if ( ret!=1 )
            ret = solve(ny,nx);
    }
    
    return ret;
}

int main(){
    
    //freopen("input.txt", "r", stdin);
    
    
    int tc;
    cin >> tc;
    
    while (tc--){
        memset (map, 0, sizeof(map));
        memset (cache,-1, sizeof(cache));
        scanf("%d",&n);
        for (int i = 1; i<=n; i++)
            for (int j= 1 ; j<=n ;j++)
                scanf("%d",&map[i][j]);
        
        
        if (solve(1,1))
            printf("YES\n");
        else
            printf("NO\n");
        
        
        
    }
}
