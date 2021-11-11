class Solution {
 public:
  int kthLargestValue(vector<vector<int>>& matrix, int k) {
    const int m = matrix.size();
    const int n = matrix[0].size();

    vector<vector<int>> xors(m + 1, vector<int>(n + 1));
    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j) {
        xors[i][j] = xors[i - 1][j] ^ xors[i][j - 1] ^ xors[i - 1][j - 1] ^
                     matrix[i - 1][j - 1];
        pq.push(xors[i][j]);
        if (pq.size() > k)
          pq.pop();
      }

    return pq.top();
  }
};
