class Solution {
 public:
  long long maximumSubsequenceCount(string text, string pattern) {
    long long ans = 0;
    int count0 = 0;  // the count of the letter pattern[0]
    int count1 = 0;  // the count of the letter pattern[1]

    for (const char c : text) {
      if (c == pattern[1]) {
        ans += count0;
        ++count1;
      }
      if (c == pattern[0])
        ++count0;
    }

    // It is optimal to add pattern[0] at the beginning or add pattern[1] at the
    // end of the text.
    return ans + max(count0, count1);
  }
};
