class Solution {
 public:
  vector<int> goodIndices(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> ans;
    vector<int> dec(n, 1);  // dec[i] := continuous decreasing before i
    vector<int> inc(n, 1);  // inc[i] := continuous increasing after i

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
