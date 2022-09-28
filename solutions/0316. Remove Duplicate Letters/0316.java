class Solution {
  public String removeDuplicateLetters(String s) {
    StringBuilder sb = new StringBuilder();
    int[] count = new int[128];
    boolean[] used = new boolean[128];

    for (final char c : s.toCharArray())
      ++count[c];

    for (final char c : s.toCharArray()) {
      --count[c];
      if (used[c])
        continue;
      while (sb.length() > 0 && last(sb) > c && count[last(sb)] > 0) {
        used[last(sb)] = false;
        sb.setLength(sb.length() - 1);
      }
      used[c] = true;
      sb.append(c);
    }

    return sb.toString();
  }

  private char last(StringBuilder sb) {
    return sb.charAt(sb.length() - 1);
  }
}
