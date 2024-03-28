class Solution {
 public:
  int minSumOfLengths(vector<int>& arr, int target) {
    int ans = INT_MAX;
    int sum = 0;  // the window sum
    // best[i] := the minimum length of subarrays in arr[0..i] that have
    // sum = target
    vector<int> best(arr.size(), INT_MAX);

    for (int l = 0, r = 0; r < arr.size(); ++r) {
      sum += arr[r];  // Expand the window.
      while (sum > target)
        sum -= arr[l++];  // Shrink the window.
      if (sum == target) {
        if (l > 0 && best[l - 1] != INT_MAX)
          ans = min(ans, best[l - 1] + r - l + 1);
        best[r] = min(best[r], r - l + 1);
      }
      if (r > 0)
        best[r] = min(best[r], best[r - 1]);
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
