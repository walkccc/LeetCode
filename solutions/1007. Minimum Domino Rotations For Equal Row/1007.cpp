class Solution {
 public:
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    const int n = A.size();
    vector<int> countA(7);
    vector<int> countB(7);
    vector<int> countBoth(7);

    for (int i = 0; i < n; ++i) {
      ++countA[A[i]];
      ++countB[B[i]];
      if (A[i] == B[i])
        ++countBoth[A[i]];
    }

    for (int i = 1; i <= 6; ++i)
      if (countA[i] + countB[i] - countBoth[i] == n)
        return n - max(countA[i], countB[i]);

    return -1;
  }
};
