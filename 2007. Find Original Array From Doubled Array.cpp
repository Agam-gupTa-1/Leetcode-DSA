// 2007. Find Original Array From Doubled Array

Approach:

First we take a map, then we sort the given array changed.
We keep removing the smallest element n and 2 * n and keep putting n into the answer until changed array becomes empty.
If at anytime the we are unable to remove elements we return empty array.
  
  // code
  class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n %2 != 0)
            return {};
        
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            mp[changed[i]]++;
        }
        sort(changed.begin(), changed.end());
        for(auto &a: changed)
        {
            if(mp[a] == 0)
                continue;
            else if(mp[2*a] == 0)
                return {};
            else if(mp[a] && mp[2*a])
            {
                mp[a]--;
                ans.push_back(a);
                mp[2*a]--;
            }
        }
        return ans;
    }
};
