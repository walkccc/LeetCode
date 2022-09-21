class Solution {
 public:
  int twoSumLessThanK(vector<int>& A, int K) {
    if (A.size() < 2)
      return -1;

    int ans = -1;  // note the constraint that A[i] > 0
    int l = 0;
    int r = A.size() - 1;

    sort(begin(A), end(A));

    while (l < r)
      if (A[l] + A[r] < K) {
        ans = max(ans, A[l] + A[r]);
        ++l;
      } else {
        --r;
      }

    return ans;
  }
};
