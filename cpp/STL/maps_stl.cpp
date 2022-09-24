#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    map<string, int> m;
    int Q, qtype, Y;
    string X;
    cin >> Q;
    // for (int i=0;i<10;i++){}
    
    for (int i=0;i<Q;i++){
        cin >> qtype;
        if (qtype == 1){
            cin >> X >> Y;
            if(m.find(X)!=m.end()){
                m[X] += Y;
            }else{
                m.insert(make_pair(X, Y));    
            }
        }else if (qtype == 2) {
            cin >> X;
            m.erase(X);
        }
        else {
            cin >> X;
            if(m.find(X)!=m.end()){
                cout << m[X] << endl;
            }else{
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
