class Solution {
 public:
  int secondsToRemoveOccurrences(string s) {
    int ans = 0;
    int zeros = 0;

    for (const char c : s)
      if (c == '0')
        ++zeros;
      else if (zeros > 0)  // c == '1'
        ans = max(ans + 1, zeros);

    return ans;
  }
};
