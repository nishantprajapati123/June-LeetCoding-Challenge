// Time complexity :- O(log(n))
// Space complexity :- O(1)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size();
        int mid, ans = 0;
        
        int l = 0, h = n-1;
        while(l <= h)
        {
            mid = l + ((h-l)>>2);
            
            int dist = n - mid;
            if(citations[mid] >= dist)
            {
                ans = max(ans, dist);
                h = mid-1;
            }
            else
                l = mid+1;
        }
        
        return ans;
    }
};