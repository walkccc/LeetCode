class Solution {
 public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    constexpr int kMod = 1'000'000'007;

    auto subarraysAndSumNoGreaterThan = [&](int m) -> pair<int, long> {
      int count = 0;   // # of subarrays <= m
      long total = 0;  // sum(subarrays)
      int sum = 0;     // current sum (will be added to `total` in each loop)
      int window = 0;  // window sum (can be extend and shrink)

      for (int i = 0, j = 0; j < n; ++j) {
        sum += nums[j] * (j - i + 1);
        window += nums[j];  // extend each subarray ends w/ j
        while (window > m) {
          sum -= window;
          window -= nums[i++];  // shrink the window
        }
        count += j - i + 1;
        total += sum;
      }

      return {count, total};
    };

    // [L, R] is the possible range of the sum of any subarray
    const int L = *min_element(begin(nums), end(nums));
    const int R = accumulate(begin(nums), end(nums), 0);

    auto firstKSubarraysSum = [&](int k) -> long {
      int l = L;
      int r = R;

      while (l < r) {
        const int m = l + (r - l) / 2;
        if (subarraysAndSumNoGreaterThan(m).first < k)
          l = m + 1;
        else
          r = m;
      }

      const auto& [count, total] = subarraysAndSumNoGreaterThan(l);
      // when count != k, there're subarray(s) have the same sum as l
      return total - l * (count - k);
    };

    return (firstKSubarraysSum(right) - firstKSubarraysSum(left - 1)) % kMod;
  }
};
