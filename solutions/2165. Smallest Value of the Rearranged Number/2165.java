class Solution {
  public long smallestNumber(long num) {
    String[] digits = String.valueOf(Math.abs(num)).split("");
    String s = Stream.of(digits).sorted().collect(Collectors.joining());
    StringBuilder sb = new StringBuilder(s);
    if (num <= 0)
      return -1 * Long.parseLong(sb.reverse().toString());
    if (sb.charAt(0) == '0') {
      final int firstNonZeroIndex = sb.lastIndexOf("0") + 1;
      sb.setCharAt(0, sb.charAt(firstNonZeroIndex));
      sb.setCharAt(firstNonZeroIndex, '0');
    }
    return Long.parseLong(sb.toString());
  }
}
