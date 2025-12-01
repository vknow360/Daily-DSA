class Solution {
  public:
  
    vector<int> moveY = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> moveX = {1, 2, 2, 1, -1, -2, -2, -1};
    
    bool helper(int n, vector<vector<int>> &board, int mvIdx, int r, int c){
        if(mvIdx == n*n) return true;
        
        for(int i = 0; i < 8; i++){
            int nxtR = r + moveY[i];
            int nxtC = c + moveX[i];
            
            if(nxtR >= 0 && nxtC >= 0 && nxtR < n && nxtC < n && board[nxtR][nxtC] == -1){
                board[nxtR][nxtC] = mvIdx;
                if(helper(n, board, mvIdx+1, nxtR, nxtC)){
                    return true;
                }
                board[nxtR][nxtC] = -1;
            }
        }
        
        return false;
    }
    vector<vector<int>> knightTour(int n) {
        // code here
        vector<vector<int>> board(n, vector<int>(n, -1));

        board[0][0] = 0;
        if(helper(n, board, 1, 0, 0))
            return board;
        else return {};    
    }
};