class Solution {
 public:
  long long maximumTotalCost(vector<int>& nums) {
    long keep = nums[0];  // the maximum cost if the last number is kept
    long flip = nums[0];  // the maximum cost if the last number is flipped

    for (int i = 1; i < nums.size(); ++i) {
      const long keepCurr = max(keep, flip) + nums[i];
      const long flipCurr = keep - nums[i];
      keep = keepCurr;
      flip = flipCurr;
    }

    return max(keep, flip);
  }
};
