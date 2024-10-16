public class Solution {
  public String smallestBeautifulString(String s, int k) {
    StringBuilder sb = new StringBuilder(s);

    for (int i = s.length() - 1; i >= 0; --i) {
      do {
        sb.setCharAt(i, (char) (sb.charAt(i) + 1));
      } while (containsPalindrome(sb, i));
      if (sb.charAt(i) < 'a' + k)
        // If sb[i] is among the first k letters, then change the letters after
        // sb[i] to the smallest ones that don't form any palindrome substring.
        return changeSuffix(sb, i + 1);
    }

    return "";
  }

  // Returns true if sb[0..i] contains any palindrome.
  private boolean containsPalindrome(StringBuilder sb, int i) {
    return (i > 0 && sb.charAt(i) == sb.charAt(i - 1)) ||
        (i > 1 && sb.charAt(i) == sb.charAt(i - 2));
  }

  // Returns a string, where replacing sb[i..n) with the smallest possible
  // letters don't form any palindrome substring.
  private String changeSuffix(StringBuilder sb, int i) {
    for (int j = i; j < sb.length(); ++j)
      for (sb.setCharAt(j, 'a'); containsPalindrome(sb, j);
           sb.setCharAt(j, (char) (sb.charAt(j) + 1)))
        ;
    return sb.toString();
  }
}
