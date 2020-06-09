// Time complexity :- O(n*m)
// Space complexity :- O(n*m)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n = s.length(), m = t.length();
        bool dp[n+1][m+1];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i == 0)
                    dp[i][j] = true;
                else if(j == 0)
                    dp[i][j] = false;
                else
                    dp[i][j] = s[i-1] == t[j-1] ? dp[i-1][j-1] : dp[i][j-1]; 
            }
        }
        return dp[n][m];
    }
};



/**********************************************/
// Time complexity :- O(m)
// Space complexity :- O(1)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n = s.length(), m = t.length();
        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            if(cnt < n && s[cnt] == t[i])
                cnt++;
        }
        return cnt == n;
    }
};