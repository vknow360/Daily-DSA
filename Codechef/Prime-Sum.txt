#include <bits/stdc++.h>
using namespace std;

bool arr[] = {
    false,
    false,
    true, //2
    true, //3
    false, //4
    true, //5
    false, //6
};

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> nums(n);
	    for(auto &x : nums) cin >> x;
	    
	    int count = 0;
	    for(int i = 0; i < n; i++){
	        for(int j = i+1; j < n; j++){
	            if(arr[(nums[i]+nums[j])]) count++;
	        }
	    }
	    cout << count << endl;
	}   

}
