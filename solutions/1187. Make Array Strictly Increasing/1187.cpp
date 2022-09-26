class Solution {
 public:
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    // dp[i] := min steps to reach i at previous round
    unordered_map<int, int> dp{{-1, 0}};

    sort(begin(arr2), end(arr2));

    for (const int a : arr1) {
      unordered_map<int, int> nextDp;
      for (const auto& [val, steps] : dp) {
        // it's possible to use the value in arr1
        if (a > val)
          nextDp[a] = min(nextDp.count(a) ? nextDp[a] : INT_MAX, steps);
        // also try the value in arr2
        const auto it = upper_bound(begin(arr2), end(arr2), val);
        if (it != cend(arr2))
          nextDp[*it] =
              min(nextDp.count(*it) ? nextDp[*it] : INT_MAX, steps + 1);
      }
      if (nextDp.empty())
        return -1;
      dp = move(nextDp);
    }

    int ans = INT_MAX;
    for (const auto& [_, steps] : dp)
      ans = min(ans, steps);
    return ans;
  }
};
