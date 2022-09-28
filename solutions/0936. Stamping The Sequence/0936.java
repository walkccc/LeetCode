class Solution {
  public int[] movesToStamp(String stamp, String target) {
    List<Integer> ans = new ArrayList<>();
    char[] T = target.toCharArray();
    // stamped[i] := true if we already stamped target by stamp on index i
    boolean[] stamped = new boolean[target.length()];
    int stampedCount = 0; // out goal is to make stampedCount = target.length()

    while (stampedCount < T.length) {
      boolean isStamped = false;
      // try to stamp target[i..i + stamp.length()) for each index
      for (int i = 0; i <= T.length - stamp.length(); ++i) {
        if (stamped[i])
          continue;
        final int stampified = stampify(stamp, T, i);
        if (stampified == 0)
          continue;
        stampedCount += stampified;
        isStamped = true;
        stamped[i] = true;
        ans.add(i);
      }
      // after trying stamp each index, we can't find a valid stamp
      if (!isStamped)
        return new int[] {};
    }

    Collections.reverse(ans);
    return ans.stream().mapToInt(Integer::intValue).toArray();
  }

  // stamp target[i..i + stamp.length()) and return # of newly stamped chars
  // e.g. stampify("abc", "ababc", 2) returns 3 because target becomes "ab***"
  private int stampify(final String stamp, char[] T, int s) {
    int stampified = stamp.length();

    for (int i = 0; i < stamp.length(); ++i)
      if (T[s + i] == '*') // already stamped
        --stampified;
      else if (T[s + i] != stamp.charAt(i))
        return 0; // we can't stamp on index i

    Arrays.fill(T, s, s + stamp.length(), '*');

    return stampified;
  }
}
