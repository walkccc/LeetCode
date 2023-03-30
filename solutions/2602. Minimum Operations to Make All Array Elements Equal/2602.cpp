class Solution {
 public:
  vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
    const int n = nums.size();
    vector<long long> ans;
    vector<long long> prefix{0};

    sort(begin(nums), end(nums));

    for (int i = 0; i < n; ++i)
      prefix.push_back(prefix.back() + nums[i]);

    for (const long long query : queries) {
      const int i = upper_bound(begin(nums), end(nums), query) - begin(nums);
      // Since nums[0:i] <= query, nums[i:] > query, we should
      // - increase each num in nums[0:i] to `query` and
      // - decrease each num in nums[i:] to `query`.
      const long long inc = query * i - prefix[i];
      const long long dec = prefix[n] - prefix[i] - query * (n - i);
      ans.push_back(inc + dec);
    }

    return ans;
  }
};
