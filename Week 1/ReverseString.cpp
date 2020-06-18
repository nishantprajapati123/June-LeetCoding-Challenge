// Time complexity :- O(n)
// Space complexity :- O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        
        for(int i=0;i<s.size()/2;i++)
        {
            swap(s[i], s[s.size()-i-1]);
        }
    }
};