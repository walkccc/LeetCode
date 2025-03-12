class Solution {
  public String nearestPalindromic(String n) {
    final long[] palindromes = getPalindromes(n);
    return Math.abs(palindromes[0] - Long.parseLong(n)) <=
            Math.abs(palindromes[1] - Long.parseLong(n))
        ? String.valueOf(palindromes[0])
        : String.valueOf(palindromes[1]);
  }

  // Returns the two closest palindromes to the given number.
  private long[] getPalindromes(final String s) {
    final long num = Long.parseLong(s);
    final int n = s.length();
    long[] palindromes = new long[2];
    final String half = s.substring(0, (n + 1) / 2);
    final String reversedHalf = new StringBuilder(half.substring(0, n / 2)).reverse().toString();
    final long candidate = Long.parseLong(half + reversedHalf);

    if (candidate < num)
      palindromes[0] = candidate;
    else {
      final String prevHalf = String.valueOf(Long.parseLong(half) - 1);
      final String reversedPrevHalf =
          new StringBuilder(prevHalf.substring(0, Math.min(prevHalf.length(), n / 2)))
              .reverse()
              .toString();
      if (n % 2 == 0 && Long.parseLong(prevHalf) == 0)
        palindromes[0] = 9;
      else if (n % 2 == 0 && prevHalf.equals("9"))
        palindromes[0] = Long.parseLong(prevHalf + '9' + reversedPrevHalf);
      else
        palindromes[0] = Long.parseLong(prevHalf + reversedPrevHalf);
    }

    if (candidate > num)
      palindromes[1] = candidate;
    else {
      final String nextHalf = String.valueOf(Long.parseLong(half) + 1);
      final String reversedNextHalf =
          new StringBuilder(nextHalf.substring(0, n / 2)).reverse().toString();
      palindromes[1] = Long.parseLong(nextHalf + reversedNextHalf);
    }

    return palindromes;
  }
}
