class Solution {
 public:
  int countAsterisks(string s) {
    int ans = 0;
    int bars = 0;

    for (const char c : s) {
      if (c == '|')
        ++bars;
      else if (c == '*' && bars % 2 == 0)
        ++ans;
    }

    return ans;
  }
};
