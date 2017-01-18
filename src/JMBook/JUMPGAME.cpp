/*
 * JUMPGAME.cpp
 *
 */
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#include <ctime>

using namespace std;


int g[111][111];
int d[111][111];
int dy[2] = {1,0}, dx[2] = {0,1};

int n ;
bool go (int ypos, int xpos){
    if ( ypos > n || xpos > n ) return false ;
    if ( ypos ==n && xpos ==n ) return true ;
    int & ret = d[ypos][xpos];
    if (ret !=-1 ) return ret ;
    int ny ,nx;
    for (int i = 0 ;i<2; i++){
        int now_w = g[ypos][xpos];
        ny = now_w*dy[i] + ypos;
        nx = now_w*dx[i] + xpos ;
        if ( ret != 1)
            ret = go (ny,nx);
    }
    return ret ;
}

int main(){
    int tc;
    scanf("%d",&tc);
    while (tc--){
        
        memset ( g, 0 ,sizeof(g));
        memset ( d, -1 ,sizeof(d));
        
        
        scanf("%d",&n);
        for (int i =1 ; i<=n;i++){
            for (int j=1 ;j<=n; j++){
                scanf("%d",&g[i][j]);
            }
        }
        
        if (go ( 1,1)) {
            printf("YES\n");
        }else {
            printf("NO\n");
        }
    }

}
