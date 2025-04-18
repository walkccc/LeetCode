class Solution {
  public String shortestPalindrome(String s) {
    final String t = new StringBuilder(s).reverse().toString();

    for (int i = 0; i < t.length(); ++i)
      if (s.startsWith(t.substring(i)))
        return t.substring(0, i) + s;

    return t + s;
  }
}
