class Solution {
  public int maxDivScore(int[] nums, int[] divisors) {
    int ans = -1;
    int maxScore = -1;

    for (final int divisor : divisors) {
      final int score = (int) Arrays.stream(nums).filter(num -> num % divisor == 0).count();
      if (score > maxScore) {
        ans = divisor;
        maxScore = score;
      } else if (score == maxScore) {
        ans = Math.min(ans, divisor);
      }
    }

    return ans;
  }
}
