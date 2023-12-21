class Solution {
  public int diagonalPrime(int[][] nums) {
    int ans = 0;
    for (int i = 0; i < nums.length; ++i) {
      final int a = nums[i][i];
      final int b = nums[i][nums.length - i - 1];
      if (isPrime(a))
        ans = Math.max(ans, a);
      if (isPrime(b))
        ans = Math.max(ans, b);
    }
    return ans;
  }

  private boolean isPrime(int n) {
    if (n <= 1)
      return false;
    for (int i = 2; i * i <= n; ++i)
      if (n % i == 0)
        return false;
    return true;
  }
}
