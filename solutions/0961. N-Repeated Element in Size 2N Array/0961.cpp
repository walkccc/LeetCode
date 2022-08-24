class Solution {
 public:
  int repeatedNTimes(vector<int>& A) {
    for (int i = 0; i + 2 < A.size(); ++i)
      if (A[i] == A[i + 1] || A[i] == A[i + 2])
        return A[i];

    return A.back();
  }
};
