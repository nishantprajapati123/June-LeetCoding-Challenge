// Time complexity :- O(log(n))
// Space complexity :- O(1)
    
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        long long int l = 0, h = nums.size()-1;
        long long int mid;
        
        while(l <= h)
        {
            mid = (l + h)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                l = mid+1;
            else
                h = mid-1;
        }
        return l;
    }
};