class Solution {
  public int primePalindrome(int N) {
    if (N <= 2)
      return 2;
    if (N == 3)
      return 3;
    if (N <= 5)
      return 5;
    if (N <= 7)
      return 7;
    if (N <= 11)
      return 11;

    int n = String.valueOf(N).length();

    while (true) {
      for (int num : getPalindromes(n))
        if (num >= N && isPrime(num))
          return num;
      ++n;
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
