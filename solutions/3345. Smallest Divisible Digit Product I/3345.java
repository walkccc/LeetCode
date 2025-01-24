class Solution {
  public int smallestNumber(int n, int t) {
    for (int num = n; num < n + 10; ++num)
      if (getDigitProd(num) % t == 0)
        return num;
    throw new IllegalArgumentException();
  }

  private int getDigitProd(int num) {
    int digitProd = 1;
    while (num > 0) {
      digitProd *= num % 10;
      num /= 10;
    }
    return digitProd;
  }
}
