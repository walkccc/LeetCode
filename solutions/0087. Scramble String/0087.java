class Solution {
  public boolean isScramble(String s1, String s2) {
    if (s1.equals(s2))
      return true;
    if (s1.length() != s2.length())
      return false;
    final String hashedKey = s1 + "+" + s2;
    if (memo.containsKey(hashedKey))
      return memo.get(hashedKey);

    int[] count = new int[128];

    for (int i = 0; i < s1.length(); ++i) {
      ++count[s1.charAt(i)];
      --count[s2.charAt(i)];
    }

    for (final int c : count)
      if (c != 0) {
        memo.put(hashedKey, false);
        return false;
      }

    for (int i = 1; i < s1.length(); ++i) {
      if (isScramble(s1.substring(0, i), s2.substring(0, i)) &&
          isScramble(s1.substring(i), s2.substring(i))) {
        memo.put(hashedKey, true);
        return true;
      }
      if (isScramble(s1.substring(0, i), s2.substring(s2.length() - i)) &&
          isScramble(s1.substring(i), s2.substring(0, s2.length() - i))) {
        memo.put(hashedKey, true);
        return true;
      }
    }

    memo.put(hashedKey, false);
    return false;
  }

  private Map<String, Boolean> memo = new HashMap<>();
}
