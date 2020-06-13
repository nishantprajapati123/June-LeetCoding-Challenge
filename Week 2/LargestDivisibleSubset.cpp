// Time complexity :- O(n^2)
// Space complexity :- O(n)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        if(n <= 1)  return nums;
        
        sort(nums.begin(), nums.end());
        vector<int>ptr_next(n,-1);
        vector<int>set_size(n,1);
        
        int max_len = 1, max_id = 0;
        for(int i=n-1;i>=0;i--)
        {
            int temp_max_len = 0;
            int temp_max_id = i;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]%nums[i] == 0 && set_size[j] > temp_max_len)
                {
                    temp_max_len = set_size[j];
                    temp_max_id = j;
                }
            }
            if(temp_max_id != i)
            {
                set_size[i] += set_size[temp_max_id];
                ptr_next[i] = temp_max_id;
                if(temp_max_len + 1 > max_len)
                {
                    max_len = temp_max_len;
                    max_id = i;
                }
            }
        }
        
        vector<int>ans;
        int i = max_id;
        while(i != -1)
        {
            ans.push_back(nums[i]);
            i = ptr_next[i];
        }
        return ans;
    }
};