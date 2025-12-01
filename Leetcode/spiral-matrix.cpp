class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, top = 0, right = matrix[0].size(), bottom = matrix.size();
        right--;
        bottom--;

        vector<int> ans;

        int curr = 0; // 0 -> top, 1 -> right, 2 -> bottom, 3 -> left
        while(left <= right && top <= bottom) {
            if(curr == 0){
                for(int j = left; j <= right; j++) {
                    ans.push_back(matrix[top][j]);
                }
                top++;
            }else if(curr == 1) {
                for(int j = top; j <= bottom;j++){
                    ans.push_back(matrix[j][right]);
                }
                right--;
            }else if(curr == 2) {
                for(int j = right; j >= left; j--){
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }else {
                for(int j = bottom; j >= top; j--){
                    ans.push_back(matrix[j][left]);
                }
                left++;
            }

            curr = (curr+1)%4;
        }
        return ans;
    }
};