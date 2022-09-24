#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    vector<int> nums;
    int temp;
    cin >> N;
    for (int i=0;i<N;i++){
        cin >>  temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());
    for (int i=0;i<N;i++){
        cout << nums[i] << " ";
    }
    return 0;
}