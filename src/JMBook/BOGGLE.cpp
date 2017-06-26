#include <iostream>

using namespace std ;

char map[6][6];


int dy[8] = {0,0,1,1,1,-1,-1,-1};
int dx[8] = {1,-1,0,-1,1,0,-1,1};
bool hasWordd = false;

bool inRange (int ypos , int xpos ){
    if ( ypos < 0 || xpos< 0 || ypos >= 5|| xpos >= 5) return false;
    return true ;
}

void hasWord(int ypos ,int xpos , int idx, string str){
    if ( hasWordd ) return ;
    if  (idx == (int)str.size()-1 ){ // 탈출 조건
        hasWordd = true ;
        return ;
    }
    
    for (int i = 0 ; i< 8 ; i++){
        
        int ny = dy[i] + ypos ;
        int nx = dx[i] + xpos ;
        if ( !inRange( ny, nx ) ) continue;
        if  (map[ny][nx] == str[idx+1]) {
            hasWord(ny, nx, idx+1 ,str ) ;
        }
    }
}

int main(){
    
    //    freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc ;
    
    
    while ( tc-- ){
        for (int i = 0 ; i<5 ; i++){
            cin >> map[i] ;
        }
        
        int n ;
        cin >> n;
        while ( n-- ) {
            
            
            hasWordd = false ;
            string str;
            cin >>str;
            
            for (int i = 0 ; i < 5;  i++){
                for (int j= 0 ;j<5 ; j++){
                    if ( map[i][j] == str[0] ){
                        hasWord(i,j,0,str);
                    }
                }
            }
            cout << str<< ' ';
            if ( hasWordd ){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
}

