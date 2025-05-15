class Solution {
 public:
  int maxPartitionsAfterOperations(string s, int k) {
    unordered_map<long, int> mem;
    return maxPartitionsAfterOperations(s, 0, true, 0, k, mem) + 1;
  }

 private:
  // Returns the maximum number of partitions of s[i..n), where `canChange` is
  // true if we can still change a letter, and `mask` is the bitmask of the
  // letters we've seen.
  int maxPartitionsAfterOperations(const string& s, int i, bool canChange,
                                   int mask, int k,
                                   unordered_map<long, int>& mem) {
    if (i == s.length())
      return 0;

    long key = static_cast<long>(i) << 27 | (canChange ? 1 : 0) << 26 | mask;
    if (const auto it = mem.find(key); it != mem.end())
      return it->second;

    // Initialize the result based on the current letter.
    int res = getRes(s, i, canChange, mask, 1 << (s[i] - 'a'), k, mem);

    // If allowed, explore the option to change the current letter.
    if (canChange)
      for (int j = 0; j < 26; ++j)
        res = max(res, getRes(s, i, false, mask, 1 << j, k, mem));

    return mem[key] = res;
  }

  int getRes(const string& s, int i, bool nextCanChange, unsigned mask,
             int newBit, int k, unordered_map<long, int>& mem) {
    const unsigned newMask = mask | newBit;
    if (popcount(newMask) > k)  // fresh start
      return 1 + maxPartitionsAfterOperations(s, i + 1, nextCanChange, newBit,
                                              k, mem);
    return maxPartitionsAfterOperations(s, i + 1, nextCanChange, newMask, k,
                                        mem);
  }
};
