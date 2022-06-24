class Solution {
 public:
  int largestSumAfterKNegations(vector<int>& A, int K) {
    sort(begin(A), end(A));

    for (int i = 0; i < A.size(); ++i) {
      if (A[i] > 0 || K == 0)
        break;
      A[i] = -A[i];
      --K;
    }

    return accumulate(begin(A), end(A), 0) -
           (K % 2) * *min_element(begin(A), end(A)) * 2;
  }
};
