class Solution {
 public:
  int partitionString(string s) {
    int ans = 1;
    int usedMask = 0;

    for (const char c : s) {
      const int i = c - 'a';
      if (usedMask >> i & 1) {
        usedMask = 1 << i;
        ++ans;
      } else {
        usedMask |= 1 << i;
      }
    }

    return ans;
  }
};
