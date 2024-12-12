class Solution {
  public int superpalindromesInRange(String left, String right) {
    int ans = 0;
    Long l = Long.valueOf(left);
    Long r = Long.valueOf(right);

    for (long i = (long) Math.sqrt(l); i * i <= r;) {
      long palindrome = nextPalindrome(i);
      long squared = palindrome * palindrome;
      if (squared <= r && isPalindrome(squared))
        ++ans;
      i = palindrome + 1;
    }

    return ans;
  }

  private long nextPalindrome(long num) {
    final String s = String.valueOf(num);
    final int n = s.length();

    String half = s.substring(0, (n + 1) / 2);
    String reversedHalf = new StringBuilder(half.substring(0, n / 2)).reverse().toString();
    final long candidate = Long.valueOf(half + reversedHalf);
    if (candidate >= num)
      return candidate;

    half = String.valueOf(Long.valueOf(half) + 1);
    reversedHalf = new StringBuilder(half.substring(0, n / 2)).reverse().toString();
    return Long.valueOf(half + reversedHalf);
  }

  private boolean isPalindrome(long num) {
    final String s = String.valueOf(num);
    int l = 0;
    int r = s.length() - 1;

    while (l < r)
      if (s.charAt(l++) != s.charAt(r--))
        return false;

    return true;
  }
}
