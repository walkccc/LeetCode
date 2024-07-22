class Solution {
 public:
  int maxScore(vector<int>& nums) {
    // The optimal next step is the highest number in the remaining suffix.
    int ans = 0;
    int suffixMax = 0;

    for (int i = nums.size() - 1; i > 0; --i) {
      suffixMax = max(suffixMax, nums[i]);
      ans += suffixMax;
    }

    return ans;
  }
};
