class Solution {
  public int alternateDigitSum(int n) {
    int ans = 0;
    int sign = 1;

    for (; n > 0; n /= 10) {
      sign *= -1;
      ans += sign * n % 10;
    }

    return sign * ans;
  }
}
