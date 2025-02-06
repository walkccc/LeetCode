class Solution {
 public:
  int binarySearchableNumbers(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    // prefixMaxs[i] := max(nums[0..i))
    vector<int> prefixMaxs(n);
    // suffixMins[i] := min(nums[i + 1..n))
    vector<int> suffixMins(n);

    // Fill in `prefixMaxs`.
    prefixMaxs[0] = INT_MIN;
    for (int i = 1; i < n; ++i)
      prefixMaxs[i] = max(prefixMaxs[i - 1], nums[i - 1]);

    // Fill in `suffixMins`.
    suffixMins[n - 1] = INT_MAX;
    for (int i = n - 2; i >= 0; --i)
      suffixMins[i] = min(suffixMins[i + 1], nums[i + 1]);

    for (int i = 0; i < n; ++i)
      if (prefixMaxs[i] < nums[i] && nums[i] < suffixMins[i])
        ++ans;

    return ans;
  }
};
