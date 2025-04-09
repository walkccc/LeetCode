class Solution {
  public int maxIncreasingGroups(List<Integer> usageLimits) {
    int ans = 1; // the next target length
    long availableLimits = 0;

    Collections.sort(usageLimits);

    for (final int usageLimit : usageLimits) {
      availableLimits += usageLimit;
      // Can create groups 1, 2, ..., ans.
      if (availableLimits >= ans * (long) (ans + 1) / 2)
        ++ans;
    }

    return ans - 1;
  }
}
