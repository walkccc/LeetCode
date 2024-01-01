class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    int ans = 0;
    unordered_set<int> seen{nums.begin(), nums.end()};

    for (int num : nums) {
      // `num` is the start of a sequence.
      if (seen.count(num - 1))
        continue;
      int length = 1;
      while (seen.count(++num))
        ++length;
      ans = max(ans, length);
    }

    return ans;
  }
};
