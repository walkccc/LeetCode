class Solution {
 public:
  int getMaxGridHappiness(int m, int n, int introvertsCount,
                          int extrovertsCount) {
    return getMaxGridHappiness(m, n, 0, 0, 0, introvertsCount, extrovertsCount);
  }

 private:
  int dp[25][64][64][7][7] = {};

  // Calculates the cost based on left and up neighbors.
  //
  // The `diff` parameter represents the happiness change due to the current
  // placed person in (i, j). We add `diff` each time we encounter a neighbor
  // (left or up) who is already placed.
  //
  // Case 1: If the neighbor is an introvert, we subtract 30 from cost.
  // Case 2: If the neighbor is an extrovert, we add 20 to from cost.
  int getPlacementCost(int n, int i, int j, int inMask, int exMask, int diff) {
    int cost = 0;
    if (i > 0) {
      if ((1 << (n - 1)) & inMask)
        cost += diff - 30;
      if ((1 << (n - 1)) & exMask)
        cost += diff + 20;
    }
    if (j > 0) {
      if (1 & inMask)
        cost += diff - 30;
      if (1 & exMask)
        cost += diff + 20;
    }
    return cost;
  }

  int getMaxGridHappiness(int m, int n, int pos, int inMask, int exMask,
                          int inCount, int exCount) {
    // `inMask` is the placement of introvert people in the last n cells.
    // e.g. if we have m = 2, n = 3, i = 1, j = 1, then inMask = 0b101 means
    //
    // ? 1 0
    // 1 x ? (x := current position)
    const int i = pos / n;
    const int j = pos % n;
    if (i == m)
      return 0;
    if (dp[pos][inMask][exMask][inCount][exCount] > 0)
      return dp[pos][inMask][exMask][inCount][exCount];

    const int shiftedInMask = (inMask << 1) & ((1 << n) - 1);
    const int shiftedExMask = (exMask << 1) & ((1 << n) - 1);

    const int skip = getMaxGridHappiness(m, n, pos + 1, shiftedInMask,
                                         shiftedExMask, inCount, exCount);
    const int placeIntrovert =
        inCount > 0
            ? 120 + getPlacementCost(n, i, j, inMask, exMask, -30) +
                  getMaxGridHappiness(m, n, pos + 1, shiftedInMask | 1,
                                      shiftedExMask, inCount - 1, exCount)
            : INT_MIN;
    const int placeExtrovert =
        exCount > 0
            ? 40 + getPlacementCost(n, i, j, inMask, exMask, 20) +
                  getMaxGridHappiness(m, n, pos + 1, shiftedInMask,
                                      shiftedExMask | 1, inCount, exCount - 1)
            : INT_MIN;
    return dp[pos][inMask][exMask][inCount][exCount] =
               max({skip, placeIntrovert, placeExtrovert});
  }
};
