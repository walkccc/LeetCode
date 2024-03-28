class Solution {
 public:
  int maximumDifference(vector<int>& nums) {
    int ans = -1;
    int min = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > min)
        ans = max(ans, nums[i] - min);
      min = std::min(min, nums[i]);
    }

    return ans;
  }
};
