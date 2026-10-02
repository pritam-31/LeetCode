class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        int leftMax[20000], rightMax[20000];

        // Left Max (1st Loop)
        leftMax[0] = height[0];

        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Right Max (2nd Loop)
        rightMax[n - 1] = height[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // Calculate water (3rd Loop)
        int waterTrapped = 0;

        for(int i = 0; i < n; i++) {

            int currWater = min(leftMax[i], rightMax[i]) - height[i];
            waterTrapped += currWater;
        }

        return waterTrapped;
    }
};