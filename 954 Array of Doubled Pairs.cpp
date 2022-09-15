// 954. Array of Doubled Pairs

Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.
  
  
Approach -->
  for every number there should be double of it in array
  1) sort the array to get smallest element or not double element first
  2) then one by one delete number and its double from the array 
  3) if array become empty then this arrangement is possible
  
 // code
 
 class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for(auto &a: arr)
        {
            mp[a]++;
        }
        sort(arr.begin(), arr.end());
        
        for(auto &x: arr)
        {
            if(mp[x] == 0)
                continue;
            else if(mp[2*x] == 0)
                return false;
            else
            {
                mp[x]--; mp[2*x]--;
            }
        }
        for(auto &m: mp)
            if(m.second != 0)
                return false;
        return true;
        
    }
};
