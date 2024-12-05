class Solution {
 public:
  int maximumUniqueSubarray(vector<int>& nums) {
    int ans = 0;
    int score = 0;
    unordered_set<int> seen;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      while (!seen.insert(nums[r]).second) {
        score -= nums[l];
        seen.erase(nums[l++]);
      }
      score += nums[r];
      ans = max(ans, score);
    }

    return ans;
  }
};
