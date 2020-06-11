class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int left = 0, right = n-1, middle = 0;
        
        while(middle <= right)
        {
            if(nums[middle] == 0)
                swap(nums[left++], nums[middle++]);
            else if(nums[middle] == 1)
                middle++;
            else
                swap(nums[middle], nums[right--]);
        }
    }
};