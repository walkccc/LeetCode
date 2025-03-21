class Solution {
  public int primePalindrome(int n) {
    if (n <= 2)
      return 2;
    if (n == 3)
      return 3;
    if (n <= 5)
      return 5;
    if (n <= 7)
      return 7;
    if (n <= 11)
      return 11;

    int nLength = String.valueOf(n).length();

    while (true) {
      for (final int num : getPalindromes(nLength))
        if (num >= n && isPrime(num))
          return num;
      ++nLength;
    }
  }

  private List<Integer> getPalindromes(int n) {
    List<Integer> palindromes = new ArrayList<>();
    int length = n / 2;

    for (int i = (int) Math.pow(10, length - 1); i < (int) Math.pow(10, length); ++i) {
      String s = String.valueOf(i);
      String reversedS = new StringBuilder(s).reverse().toString();
      for (int j = 0; j < 10; ++j)
        palindromes.add(Integer.valueOf(s + String.valueOf(j) + reversedS));
    }

    return palindromes;
  }

  private boolean isPrime(int num) {
    for (int i = 2; i < (int) Math.sqrt(num) + 1; ++i)
      if (num % i == 0)
        return false;
    return true;
  }
}
