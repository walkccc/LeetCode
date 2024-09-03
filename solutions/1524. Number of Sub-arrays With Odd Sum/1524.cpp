class Solution {
 public:
  int numOfSubarrays(vector<int>& arr) {
    constexpr int kMod = 1'000'000'007;
    const int n = arr.size();
    long ans = 0;
    // dp0[i] := the number of subarrays that end in arr[i - 1] with an even sum
    vector<int> dp0(n + 1);
    // dp1[i] := the number of subarrays that end in arr[i - 1] with an odd sum
    vector<int> dp1(n + 1);

    for (int i = 1; i <= n; ++i) {
      if (arr[i - 1] % 2 == 1) {
        dp0[i] = dp1[i - 1];
        dp1[i] = dp0[i - 1] + 1;
      } else {
        dp0[i] = dp0[i - 1] + 1;
        dp1[i] = dp1[i - 1];
      }
      ans = (ans + dp1[i]) % kMod;
    }

    return ans;
  }
};
