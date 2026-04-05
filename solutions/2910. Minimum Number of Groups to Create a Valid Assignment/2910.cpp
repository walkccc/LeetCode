class Solution {
 public:
  int minGroupsForValidAssignment(vector<int>& nums) {
    unordered_map<int, int> count;
    int minFreq = nums.size();

    for (const int num : nums)
      ++count[num];

    for (const auto& [_, freq] : count)
      minFreq = min(minFreq, freq);

    for (int groupSize = minFreq; groupSize >= 1; --groupSize) {
      const int numGroups = getNumGroups(count, groupSize);
      if (numGroups > 0)
        return numGroups;
    }

    throw;
  }

 private:
  // Returns the number of groups if each group's size is `groupSize` or
  // `groupSize + 1`.
  int getNumGroups(unordered_map<int, int>& count, int groupSize) {
    int numGroups = 0;
    for (const auto& [_, freq] : count) {
      const int a = freq / (groupSize + 1);
      const int b = freq % (groupSize + 1);
      if (b == 0) {
        numGroups += a;
      } else if (groupSize - b <= a) {
        // Assign 1 number from `groupSize - b` out of `a` groups to this group,
        // so we'll have `a - (groupSize - b)` groups of size `groupSize + 1`
        // and `groupSize - b + 1` groups of size `groupSize`. In total, we have
        // `a + 1` groups.
        numGroups += a + 1;
      } else {
        return 0;
      }
    }
    return numGroups;
  }
};
