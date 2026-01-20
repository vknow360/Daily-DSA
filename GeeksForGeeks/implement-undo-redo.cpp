class Solution {
  public:
    string s;
    stack<char> rd;
    void append(char x) {
        // append x into document
        s.push_back(x);
    }

    void undo() {
        // undo last change
        char c = s.back();
        rd.push(c);
        s.pop_back();
    }

    void redo() {
        // redo changes
        if(rd.empty()) return;
        s.push_back(rd.top());
        rd.pop();
    }

    string read() {
        // read the document
        return s;
    }
};
