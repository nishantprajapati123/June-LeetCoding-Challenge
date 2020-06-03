// Time complexity :- O(nlog(n))
// Space complexity :- O(1)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n_2 = costs.size();
        sort(costs.begin(), costs.end(), [](vector<int>&a, vector<int>&b) -> bool
             {
                 return a[0]-a[1] < b[0]-b[1];
             });
        
        int min_cost = 0;
        for(int i=0;i<n_2;i++)
        {
            if(i < n_2/2)
            {
                min_cost += costs[i][0];
            }
            else
            {
                min_cost += costs[i][1];
            }
        }
        
        return min_cost;
    }
};