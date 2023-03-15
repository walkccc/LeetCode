class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    const int n = cardPoints.size();
    const int sum = accumulate(begin(cardPoints), end(cardPoints), 0);
    int windowSum = accumulate(begin(cardPoints), begin(cardPoints) + n - k, 0);
    int ans = sum - windowSum;

    for (int i = 0; i < k; ++i) {
      windowSum -= cardPoints[i];
      windowSum += cardPoints[i + n - k];
      ans = max(ans, sum - windowSum);
    }

    return ans;
  }
};
