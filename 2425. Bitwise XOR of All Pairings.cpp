// 2425. Bitwise XOR of All Pairings

You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).

Return the bitwise XOR of all integers in nums3

Approach --> if any number occurs even times then XOR is 0 else XOR is one
same with this question

we have to do pairing with each element of nums1 with nums2
if len of num2 is odd then each ele in num1 appears odd times in result , same with num1

result will be xor of elements of array(s) if its len is odd

// code
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1&1)
        {
            for(int i = 0; i < n2; i++)
                ans ^= nums2[i];
        }
        if(n2&1)
        {
            for(int i = 0; i < n1; i++)
                ans ^= nums1[i];
        }
        return ans;
    }
};
