// 1457. Pseudo-Palindromic Paths in a Binary Tree

// solution 1 using extra frequency array
class Solution {
public:
    void solve(TreeNode *&root, vector<int> &freq, int &cnt)
    {
        if(root == nullptr)
            return;
        
        freq[root->val]++;
        
        if(root->left == nullptr && root->right == nullptr){
            int count = 0;
            for(auto &a: freq)
                if(a%2 != 0)
                    count++;
            if(count <= 1)
                cnt++;
            freq[root->val]--;
            return;
        }
        
        solve(root->left, freq, cnt);
        solve(root->right, freq, cnt);
        freq[root->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10, 0);
        int cnt = 0;
        solve(root, freq, cnt);
        return cnt;
    }
};

// Solution 2
bitset article link -- https://www.tutorialspoint.com/cpp_standard_library/bitset.htm

class Solution {
public:
    void solve(TreeNode *&root, bitset<10> &b, int &cnt)
    {
        if(root == nullptr)
            return;
        
        b.operator^= (1 << root->val);// set
        
        if(root->left == nullptr && root->right == nullptr){
            if(b.count() <= 1)
                cnt++;
            b.operator^= (1 << root->val);// reset the frequency
            return;
        }
        
        solve(root->left, b, cnt);
        solve(root->right, b, cnt);
        b.operator^= (1 << root->val); // reset
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        bitset<10> b(0);
        int cnt = 0;
        solve(root, b, cnt);
        return cnt;
    }
};
TC = O(n*10)
 SC = O(10bits)
  
