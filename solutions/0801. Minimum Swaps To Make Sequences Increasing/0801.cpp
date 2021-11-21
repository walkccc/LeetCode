class Solution {
 public:
  int minSwap(vector<int>& A, vector<int>& B) {
    vector<int> keepAt(A.size(), INT_MAX);
    vector<int> swapAt(A.size(), INT_MAX);
    keepAt[0] = 0;
    swapAt[0] = 1;

    for (int i = 1; i < A.size(); ++i) {
      if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
        keepAt[i] = keepAt[i - 1];
        swapAt[i] = swapAt[i - 1] + 1;
      }
      if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
        keepAt[i] = min(keepAt[i], swapAt[i - 1]);
        swapAt[i] = min(swapAt[i], keepAt[i - 1] + 1);
      }
    }

    return min(keepAt.back(), swapAt.back());
  }
};
