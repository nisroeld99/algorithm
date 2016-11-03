/*
 * removeChar.cpp
 *
 */
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<char, bool> mp;

void go( char str[]){
    
    int to = 0 ;
    
    for (int i = 0 ; i< strlen(str) ; i++){
        if ( mp[str[i]] == true ){ // 삭제 문자열이라면
            
        }
        else {
            str[to] = str[i];
            to ++;
        }
    }
    for (int i= to ; i< strlen(str) ; i++)
        str[i] = '\0';
    
    
}


int main() {
    char str[100];
    char remov[10];
    scanf("%[^\n]s", str);
    getchar();
    scanf("%[^\n]s",remov);
    getchar();
    for (int i = 0;  i< strlen(remov) ; i++){
        mp [remov[i] ] = true;
    }
    go ( str );
    printf("%s\n",str);
}
