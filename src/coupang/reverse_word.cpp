/* 
 * 버퍼 없이 단어를 reverse 하는 방법 
 *
 * reverse_word.cpp
 *
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;


void reverse_word (char s1[]);
void reverse_string(char s1[] ,int start, int end );
    

int main() {
    char s[1000] ;
    scanf("%[^\n]s",s);
    reverse_word(s);
    printf("%s\n",s);
    

}
void reverse_string(char s1[] ,int start , int end ){
    while ( start <= end )  {
        char temp  =  s1[start];
        s1[start] = s1[end];
        s1[end] =temp ;
        start++ , end -- ;
    }
}


void reverse_word (char s1[]){
    int start = 0 ; int end= 0 ;;
    int point= 0  ;
    reverse_string(s1,0,  (int)strlen(s1)-1 ) ;
    
    
    while ( start  <= (int)strlen(s1)-1  ) {
        while ( s1[point] != ' ' && point <= (int)strlen(s1) -1 ){
            point++;
        }
        end= point -1 ;
        reverse_string(s1,start, end);
        
        start = end+2 ;
        point = start ;
   }    
}

