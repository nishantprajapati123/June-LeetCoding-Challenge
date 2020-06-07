// Time complexity :- O(n^2)
// Space complexity :- O(n)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<int>dp(amount+1, 0);
        dp[0] = 1;
        
        for(int c=0;c<coins.size();c++)
        {
            for(int s=0;s<amount+1;s++)
            {
                if(coins[c] > s) continue;
                dp[s] += dp[s - coins[c]];
            }
        }
        
        return dp[amount];
    }
};