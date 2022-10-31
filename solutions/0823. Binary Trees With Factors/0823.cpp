class Solution {
 public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    constexpr int kMod = 1'000'000'007;
    const int n = arr.size();
    // dp[i] := # of binary trees with arr[i] as root
    vector<long> dp(n, 1);
    unordered_map<int, int> numToIndex;

    sort(begin(arr), end(arr));

    for (int i = 0; i < n; ++i)
      numToIndex[arr[i]] = i;

    for (int i = 0; i < n; ++i)  // arr[i] is root
      for (int j = 0; j < i; ++j)
        if (arr[i] % arr[j] == 0) {  // arr[j] is left subtree
          const int right = arr[i] / arr[j];
          if (numToIndex.count(right)) {
            dp[i] += dp[j] * dp[numToIndex[right]];
            dp[i] %= kMod;
          }
        }

    return accumulate(begin(dp), end(dp), 0L) % kMod;
  }
};
