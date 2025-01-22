class Solution {
 public:
  int countValidSelections(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    vector<int> prefix(n);  // sum(nums[0..i - 1])
    vector<int> suffix(n);  // sum(nums[i + 1..n - 1])

    for (int i = 1; i < n; ++i)
      prefix[i] = prefix[i - 1] + nums[i - 1];

    for (int i = n - 2; i >= 0; --i)
      suffix[i] = suffix[i + 1] + nums[i + 1];

    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0)
        continue;
      if (prefix[i] == suffix[i])
        ans += 2;  // Go to either direction.
      if (abs(prefix[i] - suffix[i]) == 1)
        ans += 1;  // Go to the direction with the larger sum.
    }

    return ans;
  }
};
