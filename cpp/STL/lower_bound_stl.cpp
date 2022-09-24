#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    int N, Q;
    cin >> N;
    vector<int> nums;
    for (int i=0;i<N;i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cin >> Q;
    int cur_query;
    // for (int i=0;i<10;i++){}
    for (int i=0;i<Q;i++){
        cin >> cur_query;
        auto low_bnd = lower_bound(nums.begin(), nums.end(), cur_query);
        if (nums[low_bnd - nums.begin()] == cur_query){
            cout << "Yes" << " " << low_bnd - nums.begin() + 1 << endl;
        }
        else{
            cout << "No" << " " << low_bnd - nums.begin() + 1 << endl;
        }
    }
    
    return 0;
}
