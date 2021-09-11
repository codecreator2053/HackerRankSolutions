#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int arr_num, q_num, arr_size, value, x, y;
    cin >> arr_num >> q_num;
    vector<vector<int>> n_vec;
    for(int i=0; i<arr_num;i++){
         cin >> arr_size;
         vector<int> i_vec;
         for(int j=0;j<arr_size;j++){
             cin >> value;
             i_vec.push_back(value);
         }
         n_vec.push_back(i_vec);
    } 
    
    for(int i=0;i<q_num;i++){
        cin >> x >> y;
        cout << n_vec[x][y] << endl;
    }
    return 0;
}