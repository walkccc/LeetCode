class Solution {
 public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    constexpr int kMod = 1'000'000'007;

    auto subarraysAndSumNoGreaterThan = [&](int m) -> pair<int, long> {
      int count = 0;   // the number of subarrays <= m
      long total = 0;  // sum(subarrays)
      int sum = 0;     // the current sum
      int window = 0;  // the window sum

      for (int i = 0, j = 0; j < n; ++j) {
        sum += nums[j] * (j - i + 1);
        window += nums[j];  // Extend each subarray that ends in j.
        while (window > m) {
          sum -= window;
          window -= nums[i++];  // Shrink the window.
        }
        count += j - i + 1;
        total += sum;
      }

      return {count, total};
    };

    // [L, R] is the possible range of the sum of any subarray.
    const int L = ranges::min(nums);
    const int R = accumulate(nums.begin(), nums.end(), 0);

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
      // If count != k, there're subarray(s) have the same sum as l.
      return total - l * (count - k);
    };

    return (firstKSubarraysSum(right) - firstKSubarraysSum(left - 1)) % kMod;
  }
};
