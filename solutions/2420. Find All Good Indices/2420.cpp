class Solution {
 public:
  // Same as 2100. Find Good Days to Rob the Bank
  vector<int> goodIndices(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> ans;
    // dec[i] := 1 + the number of continuous decreasing numbers before i
    vector<int> dec(n, 1);
    // inc[i] := 1 + the number of continuous increasing numbers after i
    vector<int> inc(n, 1);

    for (int i = 1; i < n; ++i)
      if (nums[i - 1] >= nums[i])
        dec[i] = dec[i - 1] + 1;

    for (int i = n - 2; i >= 0; --i)
      if (nums[i] <= nums[i + 1])
        inc[i] = inc[i + 1] + 1;

    for (int i = k; i < n - k; ++i)
      if (dec[i - 1] >= k && inc[i + 1] >= k)
        ans.push_back(i);

    return ans;
  }
};
