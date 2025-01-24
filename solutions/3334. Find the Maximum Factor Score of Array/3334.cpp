class Solution {
 public:
  long long maxScore(vector<int>& nums) {
    const int n = nums.size();
    // prefixGcd[i] := GCD of nums[0..i]
    // prefixLcm[i] := LCM of nums[0..i]
    const auto [prefixGcd, prefixLcm] = getPrefix(nums);
    // suffixGcd[i] := GCD of nums[i..n - 1]
    // suffixLcm[i] := LCM of nums[i..n - 1]
    const auto [suffixGcd, suffixLcm] = getSuffix(nums);
    long ans = suffixGcd[0] * suffixLcm[0];

    for (int i = 0; i < n; ++i) {
      const long gcd1 = i > 0 ? prefixGcd[i - 1] : 0;
      const long gcd2 = i + 1 < n ? suffixGcd[i + 1] : 0;
      const long lcm1 = i > 0 ? prefixLcm[i - 1] : 1;
      const long lcm2 = i + 1 < n ? suffixLcm[i + 1] : 1;
      const long score = gcd(gcd1, gcd2) * lcm(lcm1, lcm2);
      ans = max(ans, score);
    }

    return ans;
  }

 private:
  // Returns the prefix GCD and LCM arrays.
  pair<vector<long>, vector<long>> getPrefix(const vector<int>& nums) {
    vector<long> prefixGcd;
    vector<long> prefixLcm;
    long currGcd = 0;
    long currLcm = 1;
    for (const int num : nums) {
      currGcd = gcd(currGcd, num);
      currLcm = lcm(currLcm, num);
      prefixGcd.push_back(currGcd);
      prefixLcm.push_back(currLcm);
    }
    return {prefixGcd, prefixLcm};
  }

  // Returns the suffix GCD and LCM arrays.
  pair<vector<long>, vector<long>> getSuffix(const vector<int>& nums) {
    vector<long> suffixGcd;
    vector<long> suffixLcm;
    long currGcd = 0;
    long currLcm = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      currGcd = gcd(currGcd, nums[i]);
      currLcm = lcm(currLcm, nums[i]);
      suffixGcd.push_back(currGcd);
      suffixLcm.push_back(currLcm);
    }
    ranges::reverse(suffixGcd);
    ranges::reverse(suffixLcm);
    return {suffixGcd, suffixLcm};
  }
};
