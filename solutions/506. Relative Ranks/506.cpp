class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    const int n = nums.size();
    vector<string> ans(n);
    vector<int> indices(n);

    iota(indices.begin(), indices.end(), 0);

    ranges::sort(indices,
                 [&](const int a, const int b) { return nums[a] > nums[b]; });

    for (int i = 0; i < n; ++i)
      if (i == 0)
        ans[indices[0]] = "Gold Medal";
      else if (i == 1)
        ans[indices[1]] = "Silver Medal";
      else if (i == 2)
        ans[indices[2]] = "Bronze Medal";
      else
        ans[indices[i]] = to_string(i + 1);

    return ans;
  }
};
