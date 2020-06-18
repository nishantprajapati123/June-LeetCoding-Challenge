// Time complexity :- O(nm)
// Space complexity :- O(1)
class Solution {
public:
    void dfs(vector<vector<char>>& board, int x, int y, int n, int m)
    {
        if(x<0 || x>=n || y<0 || y>=m || board[x][y] == 'X' || board[x][y] == '#')
            return;
        board[x][y] = '#';
        dfs(board, x-1, y, n, m);
        dfs(board, x, y+1, n, m);
        dfs(board, x+1, y, n, m);
        dfs(board, x, y-1, n, m);
    }
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        
        if(n == 0)  return;
        
        int m = board[0].size();
        
        for(int i=0;i<n;i++)
        {
            if(board[i][0] == 'O')
                dfs(board, i, 0, n, m);
        }
        
        for(int i=0;i<m;i++)
        {
            if(board[0][i] == 'O')
                dfs(board, 0, i, n, m);
        }
        
        for(int i=0;i<n;i++)
        {
            if(board[i][m-1] == 'O')
                dfs(board, i, m-1, n, m);
        }
        
        for(int i=0;i<m;i++)
        {
            if(board[n-1][i] == 'O')
                dfs(board, n-1, i, n, m);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == '#')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};