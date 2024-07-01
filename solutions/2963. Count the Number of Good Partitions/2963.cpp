class Solution {
 public:
  int numberOfGoodPartitions(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    int ans = 1;
    // lastSeen[num] := the index of the last time `num` appeared
    unordered_map<int, int> lastSeen;

    for (int i = 0; i < nums.size(); ++i)
      lastSeen[nums[i]] = i;

    // Track the maximum right index of each running partition by ensuring that
    // the first and last occurrences of a number fall within the same
    // partition.
    int maxRight = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > maxRight)
        // Start a new partition that starts from nums[i].
        // Each partition doubles the total number of good partitions.
        ans = (ans * 2L) % kMod;
      maxRight = max(maxRight, lastSeen[nums[i]]);
    }

    return ans;
  }
};
