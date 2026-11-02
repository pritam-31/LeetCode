class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        // sort kar denge array ko
        sort(nums.begin(), nums.end());

        // abb median ko findout karen [m -> median]
        int n = nums.size();
        int m = nums[n/2];

        // abb calculate the total moves
        long long moves = 0;

        for(int i=0; i < n; i++) {
            moves += abs((long long)nums[i] - m);
        }

        return moves;
    }
};