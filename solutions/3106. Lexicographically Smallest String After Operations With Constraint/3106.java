class Solution {
  public String getSmallestString(String s, int k) {
    StringBuilder sb = new StringBuilder(s);

    for (int i = 0; i < sb.length(); ++i) {
      if (k == 0)
        break;
      final int distToA = Math.min(sb.charAt(i) - 'a', 'z' - sb.charAt(i) + 1);
      if (k >= distToA) {
        k -= distToA;
        sb.setCharAt(i, 'a');
      } else {
        // k is not enough to change the current letter to 'a', so move as
        // closer to 'a' as possible.
        sb.setCharAt(i, (char) (sb.charAt(i) - k));
        k = 0;
      }
    }

    return sb.toString();
  }
}
