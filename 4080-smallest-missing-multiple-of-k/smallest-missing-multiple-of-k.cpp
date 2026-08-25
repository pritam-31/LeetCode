class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans = k;

        while (true) {
            bool found = false;

            for (int x : nums) {
                if (x == ans) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return ans;
            }
            ans = ans + k;
        }
    }
};