class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k) {
    int ans = 0;
    long sum = 0;

    sort(begin(nums), end(nums));

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      sum += nums[r];
      while (sum + k < static_cast<long>(nums[r]) * (r - l + 1))
        sum -= nums[l++];
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
