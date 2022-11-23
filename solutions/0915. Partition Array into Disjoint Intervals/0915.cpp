class Solution {
 public:
  int partitionDisjoint(vector<int>& A) {
    const int n = A.size();
    vector<int> min(n);
    min[n - 1] = A[n - 1];
    int max = INT_MIN;

    for (int i = n - 2; i >= 0; --i)
      min[i] = std::min(min[i + 1], A[i]);

    for (int i = 0; i < n; ++i) {
      max = std::max(max, A[i]);
      if (max <= min[i + 1])
        return i + 1;
    }

    throw;
  }
};
