#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    set<int> s;
    int Q;
    int qtype;
    int value;
    cin >> Q;
    // for (int i=0;i<10;i++){} 
    for (int i=0;i<Q;i++){
        cin >> qtype;
        cin >> value; 
        if (qtype == 1){
            s.insert(value);
        }else if (qtype == 2) {
            s.erase(value);
        }
        else {
            if(s.find(value) != s.end()){
                cout << "Yes" << endl;    
            }else{
                cout << "No" << endl;    
            }
        }
    }
    return 0;
}
