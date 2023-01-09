class Solution {
 public:
  int minFlips(string target) {
    int ans = 0;
    int state = 0;

    for (const char c : target)
      if (c - '0' != state) {
        state = c - '0';
        ++ans;
      }

    return ans;
  }
};
