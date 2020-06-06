// Time complexity :- O(nlog(n))
// Space complexity :- O(n)
class Solution {
public:
    vector<int>pref_sum;
    int sum = 0;
    
    Solution(vector<int>& w) {
        pref_sum.resize(w.size());
        pref_sum[0] = w[0];
        for(int i=1;i<w.size();i++)
            pref_sum[i] = pref_sum[i-1] + w[i];
        
        sum = pref_sum[w.size()-1];
    }
    
    int pickIndex() {
        
        int rand_num = rand()%sum;
        
        int id = upper_bound(pref_sum.begin(), pref_sum.end(), rand_num) - pref_sum.begin();
        
        return id;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */