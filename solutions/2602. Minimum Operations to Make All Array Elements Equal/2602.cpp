class Solution {
 public:
  vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
    const int n = nums.size();
    vector<long long> ans;
    vector<long long> prefix{0};

    ranges::sort(nums);

    for (int i = 0; i < n; ++i)
      prefix.push_back(prefix.back() + nums[i]);

    for (const long query : queries) {
      const int i = ranges::upper_bound(nums, query) - nums.begin();
      // Since nums[0..i) <= query, nums[i..n) > `query`, we should
      // - increase each num in nums[0..i) to `query` and
      // - decrease each num in nums[i..n) to `query`.
      const long inc = query * i - prefix[i];
      const long dec = prefix[n] - prefix[i] - query * (n - i);
      ans.push_back(inc + dec);
    }

    return ans;
  }
};
