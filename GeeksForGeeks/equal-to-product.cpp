class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        int n = arr.size();
        unordered_set<long long> st;
        
        for(int i : arr) {
            if(st.count(i)) return true;
            
            if(target == 0) st.insert(0);
            else if(i == 0 || (target%i != 0) ) continue;
            else st.insert(target / i);
        }
        return false;
    }
};
