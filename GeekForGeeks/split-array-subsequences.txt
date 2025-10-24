class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        // code here
        if(k==1) return true;
        int n = arr.size();

        vector<int> freq(arr[n-1] + 1, 0);
        for(int i : arr) freq[i]++;
        
        unordered_map<int, int> mp;
        
        for(int num : arr){
            if(freq[num] == 0) continue;
            
            freq[num]--;
            
            if(mp[num-1] > 0){
                mp[num-1]--;
                mp[num]++;
            }else{
                bool poss = true;
                for(int j = 1; j < k; j++){
                    if(freq[num+j] <= 0){
                        poss = false;
                        break;
                    }
                }
                if(!poss) return false;
                for(int j = 1; j < k; j++){
                    freq[num+j]--;
                }
                
                mp[num+k-1]++;
            }
        }
        return true;
    }
};