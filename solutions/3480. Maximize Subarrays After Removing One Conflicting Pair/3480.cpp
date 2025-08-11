class Solution {
 public:
  long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
    long validSubarrays = 0;
    int maxLeft = 0;
    int secondMaxLeft = 0;
    // gains[i] := the number of additional valid subarrays we can gain if the
    // restriction at index `i` is removed
    vector<long> gains(n + 1);
    // conflicts[r] := left endpoints that conflict with subarrays ending in r
    vector<vector<int>> conflicts(n + 1);

    for (const vector<int>& pair : conflictingPairs) {
      const int a = pair[0];
      const int b = pair[1];
      conflicts[max(a, b)].push_back(min(a, b));
    }

    for (int right = 1; right <= n; ++right) {
      for (const int left : conflicts[right]) {
        if (left > maxLeft) {
          secondMaxLeft = maxLeft;
          maxLeft = left;
        } else if (left > secondMaxLeft) {
          secondMaxLeft = left;
        }
      }
      // Subarrays [maxLeft + 1..right],
      //           [maxLeft + 2..right],
      //           ...
      //           [right..right] are valid.
      validSubarrays += right - maxLeft;
      // If we remove `maxLeft` (the most restrictive conflict), we gain
      // `maxLeft - secondMaxLeft` new subarrays:
      // [secondMaxLeft + 1..right],
      // [secondMaxLeft + 2..right],
      // ...
      // [maxLeft..right].
      gains[maxLeft] += maxLeft - secondMaxLeft;
    }

    return validSubarrays + ranges::max(gains);
  }
};
