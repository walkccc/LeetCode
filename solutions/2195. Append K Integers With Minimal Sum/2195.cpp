class Solution {
 public:
  long long minimalKSum(vector<int>& nums, int k) {
    long long ans = 0;
    nums.push_back(0);
    ranges::sort(nums);

    for (int i = 0; i + 1 < nums.size(); ++i) {
      if (nums[i] == nums[i + 1])
        continue;
      const int l = nums[i] + 1;
      const int r = min(nums[i] + k, nums[i + 1] - 1);
      ans += static_cast<long long>(l + r) * (r - l + 1) / 2;
      k -= r - l + 1;
      if (k == 0)
        return ans;
    }

    if (k > 0) {
      const int l = nums.back() + 1;
      const int r = nums.back() + k;
      ans += static_cast<long long>(l + r) * (r - l + 1) / 2;
    }

    return ans;
  }
};
