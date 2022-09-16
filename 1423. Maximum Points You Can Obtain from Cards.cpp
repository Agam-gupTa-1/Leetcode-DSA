// 1423. Maximum Points You Can Obtain from Cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for(int i = 0; i < (n-k); i++)
        {
            sum += cardPoints[i];
        }
        int tsum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int ans = INT_MIN;
        ans = max(ans, tsum-sum);
        int i = 0, j = n-k;
        while(j < n){
            sum -= cardPoints[i++];
            sum += cardPoints[j++];
            ans = max(ans, tsum-sum);
        }
        return ans;
    }
};
