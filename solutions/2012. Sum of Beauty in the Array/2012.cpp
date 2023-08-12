class Solution {
 public:
  int sumOfBeauties(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    vector<int> minOfRight(n);
    minOfRight.back() = nums.back();

    for (int i = n - 2; i >= 2; --i)
      minOfRight[i] = min(nums[i], minOfRight[i + 1]);

    int maxOfLeft = nums[0];

    for (int i = 1; i <= n - 2; ++i) {
      if (maxOfLeft < nums[i] && nums[i] < minOfRight[i + 1])
        ans += 2;
      else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
        ans += 1;
      maxOfLeft = max(maxOfLeft, nums[i]);
    }

    return ans;
  }
};
