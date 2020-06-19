// Time complexity :- O(nlog(n))
// Space complexity :- O(n)
class Solution {
    vector<int>power;
    string ret;
    int prime = 10000001;
public:
    string rabin_karb(string &s, int len)
    {
        if(len == 0)    return "";
        
        int n = s.length();
        int curr = 0;
        unordered_map<int, vector<int> >hash;
        
        for(int i=0;i<len;i++)
            curr = (curr*26 + (s[i]-'a'))%prime;
        
        hash[curr] = {0};
        
        for(int i=len;i<n;i++)
        {
            curr = ((curr - power[len-1] * (s[i-len] - 'a'))%prime + prime)%prime;
            curr = (curr * 26 + (s[i] - 'a'))%prime;
            
            if(hash.find(curr) == hash.end())
                hash[curr] = {i-len+1};
            else
            {
                for(int index: hash[curr])
                {
                    string str = s.substr(i-len+1,len);
                    if(s.substr(index, len) == str)
                        return s.substr(index, len);
                }
                hash[curr].push_back({i-len+1});
            }
        }
        return "";
    }
    string longestDupSubstring(string S) {
        power.resize(S.size()+1);
        power[0] = 1;
        
        for(int i=1;i<=S.size();i++)
            power[i] = (power[i-1]*26)%prime;
        
        int l = 0, r = S.size()-1;
        
        string res = "";
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            string now = rabin_karb(S, mid);
            
            if(now.length() > res.length())
            {
                res = now;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        
        return res;
    }
};