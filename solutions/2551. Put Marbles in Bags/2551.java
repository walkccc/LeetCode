class Solution {
  public long putMarbles(int[] weights, int k) {
    // To distribute marbles into k bags, there will be k - 1 cuts. If there's a
    // cut after weights[i], then weights[i] and weights[i + 1] will be added to
    // the cost. Also, no matter how we cut, weights[0] and weights[n - 1] will
    // be counted. So, the goal is to find the max/min k - 1 weights[i] +
    // weights[i + 1].
    int[] A = new int[weights.length - 1]; // weights[i] + weights[i + 1]
    long min = 0;
    long max = 0;

    for (int i = 0; i < A.length; ++i)
      A[i] = weights[i] + weights[i + 1];

    Arrays.sort(A);

    for (int i = 0; i < k - 1; ++i) {
      min += A[i];
      max += A[A.length - 1 - i];
    }

    return max - min;
  }
}
