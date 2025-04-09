class Solution {
 public:
  string kthSmallestPath(vector<int>& destination, int k) {
    string ans;
    int v = destination[0];
    int h = destination[1];
    const int totalSteps = v + h;
    const vector<vector<int>> comb = getComb(totalSteps - 1, v);

    for (int i = 0; i < totalSteps; ++i) {
      // If 'H' is picked, we can reach ranks [1, availableRank].
      const int availableRank = comb[h + v - 1][v];
      if (availableRank >= k) {  // Should pick 'H'.
        ans += 'H';
        --h;
      } else {  // Should pick 'V'.
        k -= availableRank;
        ans += 'V';
        --v;
      }
    }

    return ans;
  }

 private:
  // C(n, k) = C(n - 1, k) + C(n - 1, k - 1)
  vector<vector<int>> getComb(int n, int k) {
    vector<vector<int>> comb(n + 1, vector<int>(k + 1));
    for (int i = 0; i <= n; ++i)
      comb[i][0] = 1;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= k; ++j)
        comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
    return comb;
  }
};
