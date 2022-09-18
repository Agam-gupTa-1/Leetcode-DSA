// 42. Trapping Rain Water

Logic of code:-
see for any given index water stored/trapped will be dependent on the height of the blocks on the left and the right.
Suppose we have this array height={0,1,0,2};
now for index 2 of this array the amount of water trapped over it will clearly depend on the maximum height on left and right which in this case are 1 and 2 respectively.
Now max height of water that can be trapped at an index will be equal to min(leftmaxheight and rightmaxheight), which in this case is 1.
now water trapped at index 2 can be calculated by subtracting height[2] from min(leftmaxheight and rightmaxheight).
and we will do this for every index.
and we will keep adding this trappedwater and will return it at the end.
  
  // code
  
  class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        vector<int> leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];
        for(int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i-1], height[i]);
        for(int i = n-2; i>= 0; i--)
        {
            rightMax[i] = max(height[i], rightMax[i+1]);
        }
            
        for(int i = 0; i < n; i++)
        {
            // int j = i, leftMax = height[i], rightMax = height[i];
            // // left se max height
            // while(j >= 0)
            //     leftMax = max(leftMax, height[j--]);
            // // right se max height
            // j = i;
            // while(j < n)
            //     rightMax = max(rightMax, height[j++]);
            water += (min(leftMax[i], rightMax[i])-height[i]);
        }
        return water;
    }
};
