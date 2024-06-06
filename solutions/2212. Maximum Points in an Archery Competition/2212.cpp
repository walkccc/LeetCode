class Solution {
 public:
  vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
    constexpr int allMask = (1 << 12) - 1;
    int maxPoint = 0;
    int maxMask = 0;

    for (int mask = 0; mask < allMask; ++mask) {
      const auto& [shotable, point] =
          getShotableAndPoint(mask, numArrows, aliceArrows);
      if (shotable && point > maxPoint) {
        maxPoint = point;
        maxMask = mask;
      }
    }

    return getBobsArrows(maxMask, numArrows, aliceArrows);
  }

 private:
  pair<bool, int> getShotableAndPoint(int mask, int leftArrows,
                                      const vector<int>& aliceArrows) {
    int point = 0;
    for (int i = 0; i < 12; ++i)
      if (mask >> i & 1) {
        leftArrows -= aliceArrows[i] + 1;
        point += i;
      }
    return {leftArrows >= 0, point};
  }

  vector<int> getBobsArrows(int mask, int leftArrows,
                            const vector<int>& aliceArrows) {
    vector<int> bobsArrows(12);
    for (int i = 0; i < 12; ++i)
      if (mask >> i & 1) {
        bobsArrows[i] = aliceArrows[i] + 1;
        leftArrows -= aliceArrows[i] + 1;
      }
    bobsArrows[0] = leftArrows;
    return bobsArrows;
  }
};
