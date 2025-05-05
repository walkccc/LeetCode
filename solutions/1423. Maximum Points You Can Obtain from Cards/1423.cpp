class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    const int n = cardPoints.size();
    const int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
    int windowSum =
        accumulate(cardPoints.begin(), cardPoints.begin() + n - k, 0);
    int ans = sum - windowSum;

    for (int i = 0; i < k; ++i) {
      windowSum -= cardPoints[i];
      windowSum += cardPoints[i + n - k];
      ans = max(ans, sum - windowSum);
    }

    return ans;
  }
};
