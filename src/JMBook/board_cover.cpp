/*
 * board_cover.cpp
 *
 */
#include <iostream>


using namespace std;

int board[51][51];
int coverType[4][3][2]=  {
    {   {0,0}, {1,0} , {0,1}  },
    {   {0,0}, {0,1} , {1,1}  },
    {   {0,0}, {1,0} , {1,1}  },
    {   {0,0}, {1,0} , {1,-1}  }
};
void input() ;
bool set (int type , int ypos, int xpos , int delta );
int cover ( );
int a,b;
int cntt = 0 ;



int main() {
    freopen("input.txt", "r", stdin);
    int tc;
    scanf("%d",&tc);
    while (tc--){
        input() ;
        if (cntt %3!=0 )  {
            printf("0\n");
            continue;
        }
        printf("%d\n", cover() );
    }
    

}

void input ( ){
    cntt= 0 ;
    scanf("%d%d",&a, &b);
    for (int i = 1; i<=a; i++){
        for (int j=1 ;j<=b ; j++){
            char c ;
            cin >> c ;
            if ( c == '#') board[i][j] = 1;
            else {
                board[i][j] = 0 ;
                cntt ++ ;
            }
        }
    }
    
    
    
    
    
}

bool set (int type ,int ypos ,int xpos ,int delta ){
    bool ok = true ;
    
    for (int i = 0 ; i<3 ; i++){
        const int ny =  ypos +  coverType[type][i][0];
        const int nx =  xpos +  coverType[type][i][1];
        if ( ny < 1 || nx < 1 || ny > a || nx > b )
            ok = false ;
        else if ( (board[ny][nx] += delta) > 1 ){ //이미 덮여져 있으면
            ok = false ;
        }
    }
    return ok  ;
}
int cover () {
    int y = -1 ; int x= -1 ;
    for (int i = 1 ; i<=a; i++){
        for (int j=1 ;j<=b; j++){
            if ( board[i][j] == 0 ){
                y = i ;
                x = j;
                break;
            }
        }
        if ( y!=-1 ) break ;
    }
    if ( y == -1 ) return 1;
    
    int ret= 0 ;
    
    for (int type = 0 ; type <4 ;type++ ){
        if ( set(type ,y, x, 1)){
            ret += cover() ;
        }
        set ( type , y, x , -1 ) ;
    }
    return ret ;
}


