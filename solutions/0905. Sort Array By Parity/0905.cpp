class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& A) {
    int l = 0;
    int r = A.size() - 1;

    while (l < r) {
      if (A[l] % 2 == 1 && A[r] % 2 == 0)
        swap(A[l], A[r]);
      if (A[l] % 2 == 0)
        ++l;
      if (A[r] % 2 == 1)
        --r;
    }

    return A;
  }
};
