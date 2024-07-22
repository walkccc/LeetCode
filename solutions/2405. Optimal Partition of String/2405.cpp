class Solution {
 public:
  int partitionString(string s) {
    int ans = 1;
    int used = 0;

    for (const char c : s) {
      const int i = c - 'a';
      if (used >> i & 1) {
        used = 1 << i;
        ++ans;
      } else {
        used |= 1 << i;
      }
    }

    return ans;
  }
};
