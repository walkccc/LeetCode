class Solution {
 public:
  long long minimumReplacement(vector<int>& nums) {
    long ans = 0;
    int mx = nums.back();

    for (int i = nums.size() - 2; i >= 0; --i) {
      const int ops = (nums[i] - 1) / mx;
      ans += ops;
      mx = nums[i] / (ops + 1);
    }

    return ans;
  }
};
