/*
 * prim.cpp
 *
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


typedef pair<int, int> ii ;
vector <ii> g[10001];
bool check[10001];
int main() {
    int v,e;
    
    scanf("%d%d",&v,&e);

    for (int i = 0 ;  i < e ; i ++ ){
        int sc1,sc2,sc3;
        scanf("%d%d%d",&sc1,&sc2,&sc3);
        
        g[sc1].push_back({sc2,sc3});
        g[sc2].push_back({sc1,sc3});
    }
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    
    for (int i = 0 ; i < g[1].size();i++){
        pq.push({g[1][i].second,g[1][i].first});
    }
    check[1]=true;
    int dab  = 0;
    while ( !pq.empty() ){
        auto now = pq.top(); pq.pop();
        int now_W = now.first;
        int now_D = now.second;
        
        if (check[now_D])continue;
        check[now_D]=true;
        dab  += now_W;
        
        for (int i = 0  ; i < g[now_D].size();i++)
            pq.push({g[now_D][i].second, g[now_D][i].first});
        
    
    }
    printf("%d\n",dab);
    
}
