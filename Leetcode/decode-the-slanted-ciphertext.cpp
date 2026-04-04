class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(rows == 1) return encodedText;

        int n = encodedText.size();
        int cols = n/rows;

        string og;
        int cl = 0;
        while(cl < cols) {
            int r = 0, c = cl;
            while(r < rows && c < cols) {
                int idx = r*cols + c;
                og.push_back(encodedText[idx]);
                r++;
                c++;
            }
            cl++;
        }
        while(og.size() > 0 && og.back() == ' ') og.pop_back();
        return og;
    }
};
