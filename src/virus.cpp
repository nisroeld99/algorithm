/*
 * virus.cpp
 *
 */
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii>iii;
typedef pair<int,iii> iiii;
int g[51][51][51];
ii d[51][51][51];
queue<iiii> q ;


int dz[6] = {0,0,1,0,-1,0} , dy[6] = {1,0,0,0,0 ,-1} , dx[6] = {0,1 ,0 ,-1,0,0};
int main(){
    
    freopen("input.txt", "r",stdin);
    int tc;
    scanf("%d",&tc);
    while (tc--){
        int n , m ;
        scanf("%d%d",&n,&m);
        for (int i = 0 ; i<m; i++){
            int x,y,z,k ;
            scanf("%d%d%d%d",&x,&y,&z,&k);
            d[z][y][x].first=0;
            d[z][y][x].second =k;
            q.push(iiii(k, iii( x,ii(y,z)  )  ));
        }
        
        while (!q.empty()){
            iiii temp = q.front(); q.pop();
            int k =temp.first;
            int x = temp.second.first;
            int y = temp.second.second.first;
            int z = temp.second.second.second;
            
            for (int i = 0 ; i<6 ; i++){
                int nx = dx[i]+ x ;
                int ny = dy[i] +y;
                int nz = dz[i] +z ;
                if (nx < 1 || ny<1 || nz < 1 || nx >n || ny>n ||nz>n) continue;
                if ( d[nz][ny][nx].second != 0 ){ //이미 무엇인가 있다면
                    if (d[nz][ny][nx].first == d[z][y][x].first +1 ){
                        if (d[nz][ny][nx].second < d[z][y][x].second ){
                            
                            d[nz][ny][nx].second = d[z][y][x].second;
                            q.push(iiii( k , iii( nx,ii(ny,nz)   )    ));
                            
                        }
                        
                    }
                }
                else {
                    q.push(iiii( k , iii( nx,ii(ny,nz)   )    ));
                    d[nz][ny][nx].first= d[z][y][x].first +1;
                    d[nz][ny][nx].second =d[z][y][x].second;
                }
            }
        }
        int dab [51];
        
        for (int i =1 ; i<= n; i++){
            for (int j=1; j<=n ;j++){
                for (int k = 1 ; k<=n ;k++){
                    dab[d[i][j][k].second] ++ ;
                }
            }
        }
        
        for (int  i =1 ; i<=m; i++)
            printf("%d ",dab[i]);
        int ans = -100;
        for (int i =1 ; i<=m ;i++){
            ans = max (ans, dab[i]);
        }
        
        
        printf("%d\n", ans);
    }
    
    
}
