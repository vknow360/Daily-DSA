class Solution
{
public:
    vector<int> nextFreqGreater(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
            freq[arr[i]]++;
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && freq[arr[st.top()]] < freq[arr[i]])
            {
                res[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
