// Reverse String II

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        
        while(j < n)
        {
            if(j-i+1 == k)
            {
                reverse(s.begin()+i, s.begin()+j+1);
                i = j+k+1;
                j += k;
            }
            j++;
        }
        if(i < n)
            reverse(s.begin()+i, s.begin()+j);
        return s;
    }
};
