class Solution {
 public:
  int minimumCost(int m, int n, vector<int>& horizontalCut,
                  vector<int>& verticalCut) {
    int cost = 0;
    int sumH = accumulate(horizontalCut.begin(), horizontalCut.end(), 0);
    int sumV = accumulate(verticalCut.begin(), verticalCut.end(), 0);

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
