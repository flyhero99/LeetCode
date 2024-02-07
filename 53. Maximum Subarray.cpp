// Dynamic Programming

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMaxSum = nums[0];
        int overallMaxSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            // only if current nums[i] is greater than all the other sum(previous_sub_arrays), then update currMaxSum with nums[i]
            // otherwise, keep adding current value nums[i] into currMaxSum, even if nums[i] < 0
            currMaxSum = max(nums[i], nums[i] + currMaxSum);
            // use a variable to monitor the global maximum value
            overallMaxSum = max(currMaxSum, overallMaxSum);
            // cout << "i: " << i << " curr:" << currMaxSum << " overall: " << overallMaxSum << endl;
        }
        return overallMaxSum;
    }
};