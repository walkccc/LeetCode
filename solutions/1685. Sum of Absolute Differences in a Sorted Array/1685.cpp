class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    const int n = nums.size();
    vector<int> ans;
    // prefix[i] := sum(nums[0..i])
    vector<int> prefix(n);
    // suffix[i] := sum(nums[i..n - 1])
    vector<int> suffix(n);

    prefix[0] = nums[0];
    for (int i = 1; i < n; ++i)
      prefix[i] = prefix[i - 1] + nums[i];

    suffix[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i)
      suffix[i] = suffix[i + 1] + nums[i];

    for (int i = 0; i < nums.size(); ++i) {
      const int left = nums[i] * (i + 1) - prefix[i];
      const int right = suffix[i] - nums[i] * (n - i);
      ans.push_back(left + right);
    }

    return ans;
  }
};
