class Solution {
 public:
  // Similar to 53. Maximum Subarray
  int maximumSum(vector<int>& arr) {
    constexpr int kMin = INT_MIN / 2;
    int ans = kMin;
    int zero = kMin;  // No deletion.
    int one = kMin;   // At most 1 deletion.

    for (const int a : arr) {
      one = max({a, one + a, zero /*delete a*/});
      zero = max(a, zero + a);
      ans = max(ans, one);
    }

    return ans;
  }
};
