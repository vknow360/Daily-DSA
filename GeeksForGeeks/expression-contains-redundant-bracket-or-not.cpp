class Solution {
  public:
    bool isOperator(char c) {
        return c=='+' || c=='-' || c=='*' || c=='/';
    }
    bool checkRedundancy(string &s) {
        // code here
        stack<char> st;
        for(char c : s) {
            if(isalpha(c)) continue;
            if(c != ')') {
                st.push(c);
            }else {
                if(st.top() == '(') return true; // ((a+b))
                bool opFound = false;
                while(!st.empty() && st.top() != '(') {
                    if(isOperator(st.top())) opFound = true;
                    st.pop();
                }
                
                if(!opFound) return true; // (a+(b)/c)
                
                if(!st.empty() && st.top() == '(') st.pop();
            }
        }
        
        return false;
    }
};
