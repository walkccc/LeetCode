class Solution {
 public:
  int smallestRangeII(vector<int>& A, int K) {
    sort(begin(A), end(A));

    int ans = A.back() - A.front();
    int left = A.front() + K;
    int right = A.back() - K;

    for (int i = 0; i + 1 < A.size(); ++i) {
      int min = std::min(left, A[i + 1] - K);
      int max = std::max(right, A[i] + K);
      ans = std::min(ans, max - min);
    }

    return ans;
  }
};
