#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size; cin >> size;
    int arr[size];
    int n;
    int i = 0;
    while (cin >> n){
        arr[i] = n;
        i++;
    }
    while (i>0){
        cout << arr[i-1] << " ";
        i--;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}