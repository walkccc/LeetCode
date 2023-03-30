class Solution {
 public:
  int sumOfFlooredPairs(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    const int kMax = *max_element(begin(nums), end(nums));
    long ans = 0;
    // count[i] := # of nums <= i
    vector<int> count(kMax + 1);

    for (const int num : nums)
      ++count[num];

    for (int i = 1; i <= kMax; ++i)
      count[i] += count[i - 1];

    for (int i = 1; i <= kMax; ++i)
      if (count[i] > count[i - 1]) {
        long sum = 0;
        for (int j = 1; i * j <= kMax; ++j) {
          const int lo = i * j - 1;
          const int hi = i * (j + 1) - 1;
          sum += (count[min(hi, kMax)] - count[lo]) * j;
        }
        ans += sum * (count[i] - count[i - 1]);
        ans %= kMod;
      }

    return ans;
  }
};
