#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n1, n2, n3, sum;
    cin >> n1 >> n2 >> n3;
    sum = n1 + n2 + n3;
    cout << sum;
    return 0;
}


// for variable number of inputs
int main2() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i, sum;
    while( cin >> i){
        sum += i;
    }
    cout << sum;
    return 0;
}
