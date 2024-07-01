class Solution {
  public String maximumNumber(String num, int[] change) {
    StringBuilder sb = new StringBuilder(num);
    boolean mutated = false;

    for (int i = 0; i < num.length(); ++i) {
      final int d = num.charAt(i) - '0';
      final char c = (char) ('0' + Math.max(d, change[d]));
      sb.setCharAt(i, c);
      if (mutated && d > change[d])
        return sb.toString();
      if (d < change[d])
        mutated = true;
    }

    return sb.toString();
  }
}
