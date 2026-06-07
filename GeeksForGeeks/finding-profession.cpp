class Solution {
  public:
    string profession(int level, int pos) {
        // code here
        pos--;
        int cnt = 0;
        while((pos) > 0) {
            pos = (pos & (pos-1));
            cnt++;
        }
        if(cnt & 1) return "Doctor";
        return "Engineer";
    }
};
