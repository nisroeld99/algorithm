#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;



int map[101][101];
int cache[101][101];
int main(){
    
    freopen("input.txt", "r", stdin);
    
    
    int tc;
    cin >> tc;
    
    while (tc--){
        memset (cache ,0 ,sizeof(cache));
        int n ;
        scanf("%d",&n);
        for (int i = 1; i<=n; i++){
            for (int j= 1; j<=i ; j++){
                scanf("%d", & map[i][j]);
            }
        }
        
        cache[1][1] = map[1][1];
        for (int i =2; i<=n; i++){
            for (int j= 1; j<=i ;j++){
                cache[i][j] = max (cache[i-1][j], cache[i-1][j-1]) + map[i][j];
            }
        }
        int ans = -1;
        for (int i =1 ; i<= n; i++){
            ans = max ( ans , cache[n][i]);
        }
        cout <<ans <<endl;
    }

}
