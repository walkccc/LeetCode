class Solution {
 public:
  int numberOfSets(int n, int k) {
    vector<vector<vector<int>>> mem(
        n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
    return numberOfSets(0, k, /*drawing=*/false, n, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  int numberOfSets(int i, int k, bool drawing, int n,
                   vector<vector<vector<int>>>& mem) {
    if (k == 0)  // Find a way to draw k segments.
      return 1;
    if (i == n)  // Reach the end.
      return 0;
    if (mem[i][k][drawing] != -1)
      return mem[i][k][drawing];
    if (drawing)
      // 1. Keep drawing at i and move to i + 1.
      // 2. Stop at i so decrease k. We can start from i for the next segment.
      return mem[i][k][drawing] = (numberOfSets(i + 1, k, true, n, mem) +
                                   numberOfSets(i, k - 1, false, n, mem)) %
                                  kMod;
    // 1. Skip i and move to i + 1.
    // 2. Start at i and move to i + 1.
    return mem[i][k][drawing] = (numberOfSets(i + 1, k, false, n, mem) +
                                 numberOfSets(i + 1, k, true, n, mem)) %
                                kMod;
  }
};
