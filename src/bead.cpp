/*
 * bead.cpp
 *
 */

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii, ii> iiii;
int ans = 987654321;
int n , m ;
//int d[101][101][101][101];
int g[101][101];

bool c[101][101][101][101];
int dy[4] ={0,0,1,-1} ,dx[4]= {1,-1,0,0};
queue<iiii> q ;
void go (int ry,int rx, int by, int bx ,int cnt  ){
    if ( cnt  > ans )return;
    if ( g[ry][rx] == 4 && g[by][bx] != 4 ){
        ans = min(ans, cnt );
        return ;
    }
    if ( c[ry][rx][by][bx])return ;
    
    for (int i=  0 ; i<4 ; i++){
        int nry = ry +dy[i];
        int nrx = rx + dx[i];
        int nby = by +dy[i];
        int nbx = bx +dx[i];
        if (nry <1 || nrx <1 || nby > n || nbx > m || nry > n || nrx > m || nby<1 || nbx<1) continue ;
        
        if (g[nby][nbx]==3 && g[nry][nrx]==3 ){
            continue;
        }
        
        else if (g[nby][nbx]!=3 && g[nry][nrx]==3 ){
            c[ry][rx][by][bx] = 1 ;
            go (ry,rx, nby,nbx ,cnt+1);
            c[ry][rx][by][bx] = 0 ;
        }
        else if (g[nby][nbx]==3 && g[nry][nrx]!=3 ){
            c[ry][rx][by][bx] = 1 ;
            go (nry,nrx, by,bx, cnt+1 ) ;
            c[ry][rx][by][bx] = 0 ;
        }
        else if (g[nby][nbx]!=3 && g[nry][nrx]!=3 ){
            c[ry][rx][by][bx] = 1 ;
            go (nry,nrx, nby,nbx,cnt+1);
            c[ry][rx][by][bx] = 0 ;
        }
        
    }
    
    
}

int main(){
    int tc;
    cin >>tc;
    
    for (int TC =1 ; TC<=tc ; TC++){
        
        
        memset (g,0,sizeof(g));
        int ry,rx, by,bx;
        scanf("%d%d",&n,&m);
        for (int i = 1; i<=n ; i++){
            for (int j=1 ;j<=m ;j++){
                scanf("%d",&g[i][j]);
                if (g[i][j] == 1){
                    ry = i;
                    rx = j;
                }
                if (g[i][j] ==2 ){
                    by = i;
                    bx = j;
                }
            }
        }
        go (ry,rx,by,bx,0);
        
        printf("%d %d\n", TC ,ans );
    }
    
    
    
}


