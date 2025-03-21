class Solution {
 public:
  int maximumScore(vector<int>& nums, int k) {
    const int n = nums.size();
    int ans = nums[k];
    int mn = nums[k];
    int i = k;
    int j = k;

    // Greedily expand the window and decrease the minimum as slow as possible.
    while (i > 0 || j < n - 1) {
      if (i == 0)
        ++j;
      else if (j == n - 1)
        --i;
      else if (nums[i - 1] < nums[j + 1])
        ++j;
      else  // nums[i - 1] >= nums[j + 1]
        --i;
      mn = min({mn, nums[i], nums[j]});
      ans = max(ans, mn * (j - i + 1));
    }

    return ans;
  }
};
