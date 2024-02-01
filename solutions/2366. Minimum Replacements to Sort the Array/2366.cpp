class Solution {
 public:
  long long minimumReplacement(vector<int>& nums) {
    long long ans = 0;

    int max = nums.back();
    for (int i = nums.size() - 2; i >= 0; --i) {
      const int ops = (nums[i] - 1) / max;
      ans += ops;
      max = nums[i] / (ops + 1);
    }

    return ans;
  }
};
