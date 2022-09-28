import java.util.Map;

class Solution {
  public String largestPalindromic(String num) {
    Map<Character, Integer> count = new HashMap<>();

    for (final char c : num.toCharArray())
      count.merge(c, 1, Integer::sum);

    final String firstHalf = getFirstHalf(count);
    final String mid = getMid(count);
    final String ans = firstHalf + mid + reversed(firstHalf);
    return ans.isEmpty() ? "0" : ans;
  }

  private String getFirstHalf(Map<Character, Integer> count) {
    StringBuilder sb = new StringBuilder();
    for (char c = '9'; c >= '0'; --c) {
      final int freq = count.getOrDefault(c, 0);
      sb.append(String.valueOf(c).repeat(freq / 2));
    }
    final int index = firstNotZeroIndex(sb);
    return index == -1 ? "" : sb.substring(index);
  }

  private int firstNotZeroIndex(StringBuilder sb) {
    for (int i = 0; i < sb.length(); ++i)
      if (sb.charAt(i) != '0')
        return i;
    return -1;
  }

  private String getMid(Map<Character, Integer> count) {
    StringBuilder sb = new StringBuilder();
    for (char c = '9'; c >= '0'; --c) {
      final int freq = count.getOrDefault(c, 0);
      if (freq % 2 == 1)
        return String.valueOf(c);
    }
    return "";
  }

  private String reversed(final String s) {
    return new StringBuilder(s).reverse().toString();
  }
}
