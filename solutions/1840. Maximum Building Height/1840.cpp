class Solution {
 public:
  int maxBuilding(int n, vector<vector<int>>& restrictions) {
    vector<vector<int>> A(restrictions);

    A.push_back({1, 0});
    A.push_back({n, n - 1});
    sort(begin(A), end(A));

    for (int i = 1; i < A.size(); ++i) {
      const int dist = A[i][0] - A[i - 1][0];
      A[i][1] = min(A[i][1], A[i - 1][1] + dist);
    }

    for (int i = A.size() - 2; i >= 0; --i) {
      const int dist = A[i + 1][0] - A[i][0];
      A[i][1] = min(A[i][1], A[i + 1][1] + dist);
    }

    int ans = 0;

    for (int i = 1; i < A.size(); ++i) {
      const int l = A[i - 1][0];
      const int r = A[i][0];
      const int hL = A[i - 1][1];
      const int hR = A[i][1];
      ans = max(ans, max(hL, hR) + (r - l - abs(hL - hR)) / 2);
    }

    return ans;
  }
};
