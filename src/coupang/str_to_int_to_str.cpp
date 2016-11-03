/*
 * str_to_int_to_str.cpp
 *
 */
#include <iostream>
#include <cstdio>
#include <map>
#include <unordered_set>
using namespace std;


int str_to_int (string str){
    int idx = 0 ;
    bool flag= true ;
    int sum = 0 ;
    if ( str[idx] == '-'){
        flag = false;
        idx ++ ;
    }
    for ( ; idx < str.size()  ; idx++){
        sum*=10 ;
        sum +=  str[idx]-'0' ;
    }
    if ( !flag ) sum*=-1;
    return sum;
    
}

string int_to_str (int num){
    string temp ="";
    string ret= "";
    bool flag = true;
    if ( num < 0) {
        flag = false;
        num*= -1 ;
    }
    
    do{
        temp += num%10 +'0';
        num/=10;
    }while ( num > 0 ) ; 
    if (!flag)
        ret += '-';
    for (int i = 0 ; i< temp.size(); i++){
        ret += temp[temp.size()-i-1] ;
    } 
    return ret ;
}
int main(){
    string str;
    cin >> str;
    int temp  = str_to_int(str);
    printf("%d\n", temp ) ;
    printf("%s\n" , int_to_str(temp).c_str() );
    return  0 ;;
}
