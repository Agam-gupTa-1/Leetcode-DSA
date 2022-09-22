// 151. Reverse Words in a String
class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, lastIndex = 0;
        int n = s.size();
        reverse(s.begin(), s.end());
        while(j < n)
        {
            // finding word
            while(j < n && s[j] == ' ') j++;
            
            // shifting word
            int startI = i;
            while(j < n && s[j] != ' ')
            {
                s[i++] = s[j++];
                lastIndex = i;
            }
            reverse(s.begin()+startI, s.begin()+i);   
            // adding space
            s[i++] = ' ';
        }
        s.resize(lastIndex);
        return s;
    }
};
