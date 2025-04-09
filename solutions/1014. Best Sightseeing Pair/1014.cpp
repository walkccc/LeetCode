class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int ans = 0;
    int bestPrev = 0;

    for (const int value : values) {
      ans = max(ans, value + bestPrev);
      bestPrev = max(bestPrev, value) - 1;
    }

    return ans;
  }
};
