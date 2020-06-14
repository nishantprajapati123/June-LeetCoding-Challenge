// Time complexity :- O(V+E)
// Space complexity :- O(V+E)
class Solution {
public:
    void dfs(vector<pair<int, int> >route[], vector<bool>vis, int price, int &ans, int node, int dst, int K)
    {
        vis[node] = true;
        if(node == dst)
        {
            ans = price;
            return;
        }
        
        if(K == 0)  return;
        for(auto child: route[node])
        {
            int u = child.first;
            int p = child.second;
            
            if(vis[u]) continue;
            if(price + p > ans) continue;
            
            dfs(route, vis, price+p, ans, u, dst, K-1);
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        vector<pair<int, int> >route[n];
        for(int i=0;i<flights.size();i++)
        {
            route[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        int ans = INT_MAX;
        vector<bool>vis(n, false);
        dfs(route, vis, 0, ans, src, dst, K+1);
        
        return ans == INT_MAX ? -1: ans;
    }
};