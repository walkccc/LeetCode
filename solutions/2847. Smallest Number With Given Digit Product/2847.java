class Solution {
  public String smallestNumber(long n) {
    if (n <= 9)
      return Long.toString(n);

    StringBuilder ans = new StringBuilder();

    for (int divisor = 9; divisor > 1; --divisor)
      while (n % divisor == 0) {
        ans.append(Integer.toString(divisor));
        n /= divisor;
      }

    return n > 1 ? "-1" : ans.reverse().toString();
  }
}
