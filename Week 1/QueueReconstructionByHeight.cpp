// Time complexity :- O(n^2)
// Space complexity :- O(n)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(), people.end(), [](vector<int>&p1, vector<int>&p2)
             {
                if(p1[0] == p2[0])  return p1[1] > p2[1];
                 return p1[0] < p2[0];
             });
        vector<vector<int> >ans;
        for(int i=people.size()-1; i>=0;i--)
            ans.insert(ans.begin() + people[i][1], people[i]);
        
        return ans;
    }
};