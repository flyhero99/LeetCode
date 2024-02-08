class Solution {
public:
    bool canJump(vector<int>& nums) {
        // // 1. Greedy: look for the farthest index we can reach
        // if(nums.size() == 0) return false;
        // bool ans = true;
        // int farthest = nums[0];
        // for(int i = 0; i < nums.size(); i++) {
        //     if (farthest < i) {
        //         ans = false;
        //         break;
        //     }
        //     farthest = max(farthest, i+nums[i]);
        // }
        // return ans;

        // 2. DP: from back to end, dp[i] represents we can jump from i to n; init dp[n-1] = true and all others as false
        int n = nums.size();
        bool dp[n+5];
        for (int i = 0; i <= n; i++) {dp[i] = false;}
        dp[n-1] = true;
        int front = n-1;
        for (int i = n-1; i >= 0; i--) {
            // if current position can reach the frontest position (which can reach to the end)
            if (i+nums[i] >= front) {
                dp[i] = true;
                front = i;
            }
        }
        return dp[0];
    }
};