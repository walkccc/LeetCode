class Solution {
 public:
  vector<int> addToArrayForm(vector<int>& A, int K) {
    for (int i = A.size() - 1; i >= 0; --i) {
      A[i] += K;
      K = A[i] / 10;
      A[i] %= 10;
    }

    while (K > 0) {
      A.insert(begin(A), K % 10);
      K /= 10;
    }

    return A;
  }
};
