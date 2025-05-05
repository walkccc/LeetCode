class Solution {
 public:
  int maxIncreasingGroups(vector<int>& usageLimits) {
    int ans = 1;  // the next target length
    long availableLimits = 0;

    ranges::sort(usageLimits);

    for (const int usageLimit : usageLimits) {
      availableLimits += usageLimit;
      // Can create groups 1, 2, ..., ans.
      if (availableLimits >= static_cast<long>(ans) * (ans + 1) / 2)
        ++ans;
    }

    return ans - 1;
  }
};
