class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<string> vec;
        for(int i : arr) {
            vec.push_back(to_string(i));
        }
        sort(vec.begin(), vec.end(), [](string a, string b) {
            string s1 = a+b;
            string s2 = b+a;
            return s1 > s2;
        });
        
        string ans;
        for(string s : vec) ans += s;
        
        if(ans[0] == '0') return "0";
        return ans;
    }
};
