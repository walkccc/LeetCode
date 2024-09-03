class Solution {
 public:
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    // dp[i] := the minimum steps to reach i at previous round
    unordered_map<int, int> dp{{-1, 0}};

    ranges::sort(arr2);

    for (const int a : arr1) {
      unordered_map<int, int> nextDp;
      for (const auto& [val, steps] : dp) {
        // It's possible to use the value in the arr1.
        if (a > val)
          nextDp[a] = min(nextDp.contains(a) ? nextDp[a] : INT_MAX, steps);
        // Also try the value in the arr2.
        if (const auto it = ranges::upper_bound(arr2, val); it != arr2.cend())
          nextDp[*it] =
              min(nextDp.contains(*it) ? nextDp[*it] : INT_MAX, steps + 1);
      }
      if (nextDp.empty())
        return -1;
      dp = std::move(nextDp);
    }

    int ans = INT_MAX;
    for (const auto& [_, steps] : dp)
      ans = min(ans, steps);
    return ans;
  }
};
