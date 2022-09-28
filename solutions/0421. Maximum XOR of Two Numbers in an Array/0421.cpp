class Solution {
 public:
  int findMaximumXOR(vector<int>& nums) {
    int ans = 0;
    int mask = 0;

    // if ans is 11100 at i = 2, it means before we reach the last two bits,
    // 11100 is the maximum XOR we have, and we're going to explore if we can
    // get another two '1's and put them into ans
    for (int i = 31; i >= 0; --i) {
      // mask grows like: 100...000, 110...000, 111...000, ..., 111...111
      mask |= 1 << i;
      unordered_set<int> prefixes;
      // we only care about the left parts,
      // if i = 2, nums = {1110, 1011, 0111}
      // -> prefixes = {1100, 1000, 0100}
      for (const int num : nums)
        prefixes.insert(num & mask);
      // if i = 1 and before this iteration, the ans is 1100,
      // we hope to grow ans to 1110, so find a candidate
      // which can give a greedy try
      const int candidate = ans | 1 << i;
      for (const int prefix : prefixes)
        if (prefixes.count(prefix ^ candidate)) {
          ans = candidate;
          break;
        }
    }

    return ans;
  }
};
