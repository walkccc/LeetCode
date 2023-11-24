class Solution {
 public:
  int countLetters(string s) {
    int ans = 0;
    int dp = 0;         // length of the running letter
    char letter = '@';  // running letter

    for (const char c : s) {
      if (c == letter) {
        ++dp;
      } else {
        dp = 1;
        letter = c;
      }
      // Add # of substrings ending at the current letter.
      ans += dp;
    }

    return ans;
  }
};
