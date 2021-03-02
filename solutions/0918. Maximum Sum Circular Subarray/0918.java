class Solution {
  public int maxSubarraySumCircular(int[] A) {
    int totalSum = 0;
    int currMaxSum = 0;
    int currMinSum = 0;
    int maxSum = Integer.MIN_VALUE;
    int minSum = Integer.MAX_VALUE;

    for (int a : A) {
      totalSum += a;
      currMaxSum = Math.max(currMaxSum + a, a);
      currMinSum = Math.min(currMinSum + a, a);
      maxSum = Math.max(maxSum, currMaxSum);
      minSum = Math.min(minSum, currMinSum);
    }

    return maxSum < 0 ? maxSum : Math.max(maxSum, totalSum - minSum);
  }
}
