class Solution {
 public:
  vector<int> numMovesStonesII(vector<int>& stones) {
    const int n = stones.size();
    int minMoves = n;

    sort(begin(stones), end(stones));

    for (int l = 0, r = 0; r < n; ++r) {
      while (stones[r] - stones[l] + 1 > n)
        ++l;
      int alreadyStored = r - l + 1;
      if (alreadyStored == n - 1 && stones[r] - stones[l] + 1 == n - 1)
        minMoves = min(minMoves, 2);
      else
        minMoves = min(minMoves, n - alreadyStored);
    }

    return {minMoves, max(stones[n - 1] - stones[1] - n + 2,
                          stones[n - 2] - stones[0] - n + 2)};
  }
};
