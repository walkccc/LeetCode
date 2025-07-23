class Solution {
  public String repeatLimitedString(String s, int repeatLimit) {
    StringBuilder sb = new StringBuilder();
    int[] count = new int[26];

    for (final char c : s.toCharArray())
      ++count[c - 'a'];

    while (true) {
      final boolean addOne = !sb.isEmpty() && shouldAddOne(sb, count);
      final int i = getLargestChar(sb, count);
      if (i == -1)
        break;
      final int repeats = addOne ? 1 : Math.min(count[i], repeatLimit);
      sb.append(String.valueOf((char) ('a' + i)).repeat(repeats));
      count[i] -= repeats;
    }

    return sb.toString();
  }

  private boolean shouldAddOne(StringBuilder sb, int[] count) {
    for (int i = 25; i >= 0; --i)
      if (count[i] > 0)
        return sb.charAt(sb.length() - 1) == 'a' + i;
    return false;
  }

  private int getLargestChar(StringBuilder sb, int[] count) {
    for (int i = 25; i >= 0; --i)
      if (count[i] > 0 && (sb.isEmpty() || sb.charAt(sb.length() - 1) != 'a' + i))
        return i;
    return -1;
  }
}
