class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& A) {
    const int n = A.size();

    for (int i = 0, j = 1; i < n; i += 2, j += 2) {
      while (i < n && A[i] % 2 == 0)
        i += 2;
      while (j < n && A[j] % 2 == 1)
        j += 2;
      if (i < n)
        swap(A[i], A[j]);
    }

    return A;
  }
};
