class Solution {
 public:
  long long findTheArrayConcVal(vector<int>& nums) {
    long long ans = 0;

    for (int i = 0, j = nums.size() - 1; i <= j; ++i, --j) {
      ans += nums[j];
      if (i < j)
        ans += nums[i] * pow(10, static_cast<int>(log10(nums[j])) + 1);
    }

    return ans;
  }
};
