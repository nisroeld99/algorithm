/*
 * notbanbok.cpp
 *
 */
#include <iostream>
#include <cstdio>
using namespace std;



int c[26] ;
char go( string str){
    for (int i = 0 ; i< str.size();  i++){
        c[ str[i] - 'a'  ] ++ ;
    }
    for (int i = 0 ; i< str.size();  i++){
        if (c[ str[i] - 'a'  ]  == 1 ){

            return str[i];
        }
    }
    printf("not exist " );
    return NULL;
}


int main() {
    string str;
    cin >> str;
    cout << go ( str )<<endl ;
}
