// Time complexity :- O(n*m)
// Space complexity :- O(1)
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
             ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = dungeon.size();
        if(n==0) return 0;
        int m = dungeon[0].size();
        
        if(dungeon[n-1][m-1]>0)
            dungeon[n-1][m-1] = 0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1)
                    
                {
                    continue;
                }
                else if(i==n-1)
                    dungeon[i][j] = min(0, dungeon[i][j] + dungeon[i][j+1]);
                else if(j == m-1)
                    dungeon[i][j] = min(0, dungeon[i][j] + dungeon[i+1][j]);
                else
                    dungeon[i][j] = min(0, max(dungeon[i][j]+dungeon[i][j+1],dungeon[i][j]+dungeon[i+1][j]));
            }
        }
        return abs(dungeon[0][0])+1;
    }
};