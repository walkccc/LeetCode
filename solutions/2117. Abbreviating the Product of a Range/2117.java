class Solution {
  public String abbreviateProduct(int left, int right) {
    final long maxSuf = 100000000000L;
    double prod = 1.0;
    long suf = 1;
    int countDigits = 0;
    int countZeros = 0;

    for (int num = left; num <= right; ++num) {
      prod *= num;
      while (prod >= 1.0) {
        prod /= 10;
        ++countDigits;
      }
      suf *= num;
      while (suf % 10 == 0) {
        suf /= 10;
        ++countZeros;
      }
      if (suf > maxSuf)
        suf %= maxSuf;
    }

    if (countDigits - countZeros <= 10) {
      final long tens = (long) Math.pow(10, countDigits - countZeros);
      return String.valueOf((long) (prod * tens + 0.5)) + "e" + String.valueOf(countZeros);
    }

    final String pre = String.valueOf((long) (prd * Math.pow(10, 5)));
    String sufStr = String.valueOf(suf);
    sufStr = sufStr.substring(sufStr.length() - 5);
    return pre + "..." + sufStr + "e" + String.valueOf(countZeros);
  }
}
