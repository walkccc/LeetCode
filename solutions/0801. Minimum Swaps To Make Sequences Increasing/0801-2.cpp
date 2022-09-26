class Solution {
 public:
  int minSwap(vector<int>& A, vector<int>& B) {
    int keepAt = 0;
    int swapAt = 1;
    int prevKeepAt = 0;
    int prevSwapAt = 1;

    for (int i = 1; i < A.size(); ++i) {
      keepAt = INT_MAX;
      swapAt = INT_MAX;
      if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
        keepAt = prevKeepAt;
        swapAt = prevSwapAt + 1;
      }
      if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
        keepAt = min(keepAt, prevSwapAt);
        swapAt = min(swapAt, prevKeepAt + 1);
      }
      prevKeepAt = keepAt;
      prevSwapAt = swapAt;
    }

    return min(keepAt, swapAt);
  }
};
