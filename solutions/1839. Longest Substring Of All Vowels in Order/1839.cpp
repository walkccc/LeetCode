class Solution {
 public:
  int longestBeautifulSubstring(string word) {
    int ans = 0;
    int count = 1;

    for (int l = 0, r = 1; r < word.length(); ++r) {
      const char curr = word[r];
      const char prev = word[r - 1];
      if (curr >= prev) {
        if (curr > prev)
          ++count;
        if (count == 5)
          ans = max(ans, r - l + 1);
      } else {
        count = 1;
        l = r;
      }
    }

    return ans;
  }
};
