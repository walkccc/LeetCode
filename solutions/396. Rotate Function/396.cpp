class Solution {
 public:
  int maxRotateFunction(vector<int>& nums) {
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    int f = 0;

    // Calculate F(0) first.
    for (int i = 0; i < nums.size(); ++i)
      f += i * nums[i];

    int ans = f;

    for (int i = nums.size() - 1; i > 0; --i) {
      f += sum - nums.size() * nums[i];
      ans = max(ans, f);
    }

    return ans;
  }
};
