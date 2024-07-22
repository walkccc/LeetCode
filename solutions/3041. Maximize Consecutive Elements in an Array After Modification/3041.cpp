class Solution {
 public:
  int maxSelectedElements(vector<int>& nums) {
    int ans = 0;
    // {num: the length of the longest consecutive elements ending in num}
    unordered_map<int, int> dp;

    ranges::sort(nums);

    for (const int num : nums) {
      dp[num + 1] = dp[num] + 1;
      dp[num] = dp[num - 1] + 1;
      ans = max({ans, dp[num], dp[num + 1]});
    }

    return ans;
  }
};
