class Solution {
  public String nearestPalindromic(String n) {
    final long[] palindromes = getPalindromes(n);

    return Math.abs(palindromes[0] - Long.valueOf(n)) <= Math.abs(palindromes[1] - Long.valueOf(n))
        ? String.valueOf(palindromes[0])
        : String.valueOf(palindromes[1]);
  }

  private long[] getPalindromes(final String s) {
    final long num = Long.valueOf(s);
    final int n = s.length();

    long[] palindromes = new long[2];
    String half = s.substring(0, (n + 1) / 2);
    String reversedHalf = new StringBuilder(half.substring(0, n / 2)).reverse().toString();
    long candidate = Long.valueOf(half + reversedHalf);

    if (candidate < num)
      palindromes[0] = candidate;
    else {
      String prevHalf = String.valueOf(Long.valueOf(half) - 1);
      String reversedPrevHalf = new StringBuilder(prevHalf.substring(0, Math.min(prevHalf.length(), n / 2))).reverse()
          .toString();
      if (n % 2 == 0 && Long.valueOf(prevHalf) == 0)
        palindromes[0] = 9;
      else if (n % 2 == 0 && (Long.valueOf(prevHalf) + 1) % 10 == 0)
        palindromes[0] = Long.valueOf(prevHalf + '9' + reversedPrevHalf);
      else
        palindromes[0] = Long.valueOf(prevHalf + reversedPrevHalf);
    }

    if (candidate > num)
      palindromes[1] = candidate;
    else {
      String nextHalf = String.valueOf(Long.valueOf(half) + 1);
      String reversedNextHalf = new StringBuilder(nextHalf.substring(0, n / 2)).reverse().toString();
      palindromes[1] = Long.valueOf(nextHalf + reversedNextHalf);
    }

    return palindromes;
  }
}