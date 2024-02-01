class Solution {
 public:
  int largestSubmatrix(vector<vector<int>>& matrix) {
    const int n = matrix[0].size();
    int ans = 0;
    vector<int> hist(n);

    for (const vector<int>& row : matrix) {
      // Accumulate the histogram if possible.
      for (int i = 0; i < n; ++i)
        hist[i] = row[i] == 0 ? 0 : hist[i] + 1;

      // Get the sorted histogram.
      vector<int> sortedHist(hist);
      ranges::sort(sortedHist);

      // Greedily calculate the answer.
      for (int i = 0; i < n; ++i)
        ans = max(ans, sortedHist[i] * (n - i));
    }

    return ans;
  }
};
