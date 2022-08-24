class Solution {
 public:
  long long maximumSubsequenceCount(string text, string pattern) {
    long long ans = 0;
    int count0 = 0;
    int count1 = 0;

    for (int i = 0; i < text.length(); ++i) {
      if (text[i] == pattern[1]) {
        ans += count0;
        ++count1;
      }
      if (text[i] == pattern[0])
        ++count0;
    }

    // adding pattern[0] in the beginning or
    // adding pattern[1] in the end is optimal
    return ans + max(count0, count1);
  }
};
