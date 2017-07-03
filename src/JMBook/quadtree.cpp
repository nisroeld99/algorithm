#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;



string reversee(string::iterator& it ){
    char head = *it;
    it++;
    if ( head == 'b' || head == 'w'){
        return string(1,head);
    }
    
    string upperLeft = reversee(it);
    string upperRight = reversee(it);
    string lowerLeft = reversee(it);
    string lowerRight = reversee(it);
    
    
    return "x" + lowerLeft + lowerRight + upperLeft + upperRight ;
}


int main(){
    
    freopen("input.txt", "r", stdin);
    
    int tc;
    cin >> tc;
    while (tc--){
        string str;
        cin >> str;
        
        
        string::iterator it = str.begin() ;
        
        cout << reversee (  it ) << endl ;
    }
}

