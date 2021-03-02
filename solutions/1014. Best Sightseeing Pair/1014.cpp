class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& A) {
    int ans = 0;
    int bestPrev = 0;

    for (int a : A) {
      ans = max(ans, a + bestPrev);
      bestPrev = max(bestPrev, a) - 1;
    }

    return ans;
  }
};
