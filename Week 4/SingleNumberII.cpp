// Time complexity :- O(n)
// Space complexity :- O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int res = 0;
        for(int i=0;i<32;i++)
        {
            int set_bits = 0;
            for(int n = 0; n<nums.size(); n++)
            {
                if(nums[n] & (1<<i))
                    set_bits++;
            }
            if(set_bits%3)
                res |= (1<<i);
        }
        
        return res;
    }
};