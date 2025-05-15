class Solution {
 public:
  int maxNonOverlapping(vector<int>& nums, int target) {
    // Ending the subarray ASAP always has a better result.
    int ans = 0;
    int prefix = 0;
    unordered_set<int> prefixes{0};

    // Greedily find the subarrays that equal to the target.
    for (const int num : nums) {
      // Check if there is a subarray ends in here and equals to the target.
      prefix += num;
      if (prefixes.contains(prefix - target)) {
        // Find one and discard all the prefixes that have been used.
        ++ans;
        prefix = 0;
        prefixes = {0};
      } else {
        prefixes.insert(prefix);
      }
    }

    return ans;
  }
};
