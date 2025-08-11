class Solution {
  public String smallestPalindrome(String s) {
    final int n = s.length();
    final String sortedHalf = getSortedHalf(s);
    return sortedHalf + (n % 2 == 1 ? String.valueOf(s.charAt(n / 2)) : "") + reversed(sortedHalf);
  }

  private String getSortedHalf(final String s) {
    final String half = s.substring(0, s.length() / 2);
    char[] chars = half.toCharArray();
    Arrays.sort(chars);
    return new String(chars);
  }

  private String reversed(final String s) {
    return new StringBuilder(s).reverse().toString();
  }
}
