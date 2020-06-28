Time complexity :- O(n+m)
Space complexity :- O(n+m)
class Solution {
public:
    void dfs(unordered_map<string, multiset<string> >&g, string from, vector<string>&ans)
    {
        
        while(g[from].size())
        {
            string to = *(g[from].begin());
            g[from].erase(g[from].begin());
            dfs(g, to, ans);
        }
        ans.push_back(from);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string, multiset<string> >g;
        for(auto &v: tickets)
            g[v[0]].insert(v[1]);
        
        vector<string>ans;
        string start = "JFK";
        dfs(g, start, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};