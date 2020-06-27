// Time complexity :- O(n*sqrt(n))
// Space complexity :- O(n)
class Solution {
public:
    int numSquares(int n) {
        
        if(n == 0)  return 0;
        vector<int>dp(n+1, INT_MAX);
        for(int i=1; i*i <= n; i++)
            dp[i*i] = 1;
        
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j*j<i;j++)
                dp[i] = min(dp[i], dp[j*j] + dp[i-(j*j)]);
        }
        
        return dp[n];
    }
};