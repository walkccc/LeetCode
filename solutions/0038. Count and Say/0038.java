class Solution {
  public String countAndSay(int n) {
    StringBuilder sb = new StringBuilder("1");

    while (--n > 0) {
      StringBuilder next = new StringBuilder();
      for (int i = 0; i < sb.length(); ++i) {
        int count = 1;
        while (i + 1 < sb.length() && sb.charAt(i) == sb.charAt(i + 1)) {
          ++count;
          ++i;
        }
        next.append(count).append(sb.charAt(i));
      }
      sb = next;
    }

    return sb.toString();
  }
}
