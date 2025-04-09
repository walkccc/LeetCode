class Solution {
 public:
  // Same as 3218. Minimum Cost for Cutting Cake I
  long long minimumCost(int m, int n, vector<int>& horizontalCut,
                        vector<int>& verticalCut) {
    long cost = 0;
    long sumH = accumulate(horizontalCut.begin(), horizontalCut.end(), 0L);
    long sumV = accumulate(verticalCut.begin(), verticalCut.end(), 0L);

    ranges::sort(horizontalCut, greater<>());
    ranges::sort(verticalCut, greater<>());

    for (int i = 0, j = 0; i < m - 1 && j < n - 1;)
      if (horizontalCut[i] > verticalCut[j]) {
        cost += horizontalCut[i] + sumV;
        sumH -= horizontalCut[i++];
      } else {
        cost += verticalCut[j] + sumH;
        sumV -= verticalCut[j++];
      }

    return cost + sumH + sumV;
  }
};
