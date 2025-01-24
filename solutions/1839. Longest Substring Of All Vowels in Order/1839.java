class Solution {
  public int longestBeautifulSubstring(String word) {
    int ans = 0;
    int count = 1;

    for (int l = 0, r = 1; r < word.length(); ++r) {
      final char curr = word.charAt(r);
      final char prev = word.charAt(r - 1);
      if (curr >= prev) {
        if (curr > prev)
          ++count;
        if (count == 5)
          ans = Math.max(ans, r - l + 1);
      } else {
        count = 1;
        l = r;
      }
    }

    return ans;
  }
}
