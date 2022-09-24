#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> nums;
    for (int i=0;i<N;i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    
    int rem_idx;
    cin >> rem_idx;
    int rem_start, rem_end; 
    cin >> rem_start >> rem_end;
    nums.erase(nums.begin() + (rem_idx-1));
    nums.erase(nums.begin()+(rem_start-1), nums.begin()+(rem_end-1));
    cout << nums.size() << endl;
    
    for (int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    return 0;
}