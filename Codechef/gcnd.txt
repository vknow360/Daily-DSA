#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vector<int> nums(n);
        for(auto& x : nums) cin >> x;
        
        sort(nums.begin(), nums.end());
        if(nums[0] == nums[n - 1]){ // all same numbers
            cout << (nums[0] - 1) << endl;
        }else if(nums[0] + 1 == nums[n-1]){ // only two consecutive numbers
            cout << (nums[0] - 1) << endl;
        }else if(n == 2){ // only two numbers
            cout << nums[1] - 1 << endl;
        }else { // more than two unique numbers
            set<int> s(nums.begin(), nums.end());
            for(int i = *(s.rbegin()) - 1; i >= 0; i--){
                if(i != *(s.begin())){
                    cout << i << endl;
                    break;
                }
            }
        }
    }
}
