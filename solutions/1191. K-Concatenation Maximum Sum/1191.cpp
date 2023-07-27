class Solution {
 public:
  int kConcatenationMaxSum(vector<int>& arr, int k) {
    constexpr int kMod = 1'000'000'007;
    const int sz = arr.size() * (k == 1 ? 1 : 2);
    const int sum = accumulate(arr.begin(), arr.end(), 0);
    // The concatenated array will be [arr1, arr2, ..., arrk].
    // If sum(arr) > 0 and k > 2, then arr2, ..., arr(k - 1) should be included.
    // Equivalently, maxSubarraySum is from arr1 and arrk.
    return (sum > 0 && k > 2 ? kadane(arr, sz) + sum * static_cast<long>(k - 2)
                             : kadane(arr, sz)) %
           kMod;
  }

 private:
  int kadane(const vector<int>& A, int sz) {
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < sz; ++i) {
      const int a = A[i % A.size()];
      sum = max(a, sum + a);
      ans = max(ans, sum);
    }
    return ans;
  }
};
