class Solution {
  public int maxScore(int[] cardPoints, int k) {
    final int n = cardPoints.length;
    final int sum = Arrays.stream(cardPoints).sum();
    int windowSum = 0;
    for (int i = 0; i < n - k; ++i)
      windowSum += cardPoints[i];

    int ans = sum - windowSum;

    for (int i = 0; i < k; ++i) {
      windowSum -= cardPoints[i];
      windowSum += cardPoints[i + n - k];
      ans = Math.max(ans, sum - windowSum);
    }

    return ans;
  }
}
