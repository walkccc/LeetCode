class Solution {
  public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
    // Greedily consider strings with `minSize`, so ignore `maxSize`.
    int ans = 0;
    int letters = 0;
    int[] count = new int[26];
    Map<String, Integer> substringCount = new HashMap<>();

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (++count[s.charAt(r) - 'a'] == 1)
        ++letters;
      while (letters > maxLetters || r - l + 1 > minSize)
        if (--count[s.charAt(l++) - 'a'] == 0)
          --letters;
      if (r - l + 1 == minSize) {
        final String sub = s.substring(l, l + minSize);
        substringCount.merge(sub, 1, Integer::sum);
        ans = Math.max(ans, substringCount.get(sub));
      }
    }

    return ans;
  }
}
