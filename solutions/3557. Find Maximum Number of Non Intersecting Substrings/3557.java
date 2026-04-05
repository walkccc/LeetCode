class Solution {
  public int maxSubstrings(String word) {
    int ans = 0;
    Map<Character, Integer> firstSeen = new HashMap<>();

    for (int i = 0; i < word.length(); ++i) {
      final char c = word.charAt(i);
      if (!firstSeen.containsKey(c)) {
        firstSeen.put(c, i);
      } else if (i - firstSeen.get(c) + 1 >= 4) {
        ++ans;
        firstSeen.clear();
      }
    }

    return ans;
  }
}
