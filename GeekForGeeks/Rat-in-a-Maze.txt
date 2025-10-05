class Solution {
  public:
    void helper(vector<vector<int>>& maze, vector<string>& ans, string path, int r, int c){
        if(r+1==maze.size() && c+1==maze.size()){
            ans.push_back(path);
            return;
        }else if((r >= maze.size() || c >= maze.size()) || maze[r][c] != 1){
            return;
        }
        int n = maze.size();
        
        maze[r][c] -= 5;
        if(r < n-1 && maze[r+1][c] == 1){
            helper(maze, ans, path+"D", r+1, c);
        }
        if(c > 0 && maze[r][c-1] == 1){
            helper(maze, ans, path+"L", r, c-1);
        }
        if(c < n-1 && maze[r][c+1] == 1){
            helper(maze, ans, path+"R", r, c+1);
        }
        if(r > 0 && maze[r-1][c] == 1){
            helper(maze, ans, path+"U", r-1, c);
        }
        
        maze[r][c] += 5;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        helper(maze, ans, "", 0, 0);
        
        return ans;
        
    }
};