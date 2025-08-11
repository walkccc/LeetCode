class Solution {
  public boolean isScramble(String s1, String s2) {
    if (s1.equals(s2))
      return true;
    final String hashKey = s1 + "+" + s2;
    if (mem.containsKey(hashKey))
      return mem.get(hashKey);

    int[] count = new int[128];

    for (int i = 0; i < s1.length(); ++i) {
      ++count[s1.charAt(i)];
      --count[s2.charAt(i)];
    }

    for (final int freq : count)
      if (freq != 0) {
        mem.put(hashKey, false);
        return false;
      }

    for (int i = 1; i < s1.length(); ++i) {
      if (isScramble(s1.substring(0, i), s2.substring(0, i)) &&
          isScramble(s1.substring(i), s2.substring(i))) {
        mem.put(hashKey, true);
        return true;
      }
      if (isScramble(s1.substring(0, i), s2.substring(s2.length() - i)) &&
          isScramble(s1.substring(i), s2.substring(0, s2.length() - i))) {
        mem.put(hashKey, true);
        return true;
      }
    }

    mem.put(hashKey, false);
    return false;
  }

  private Map<String, Boolean> mem = new HashMap<>();
}
