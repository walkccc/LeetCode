class Solution {
 public:
  vector<int> prevPermOpt1(vector<int>& A) {
    const int n = A.size();
    int l = n - 2;
    int r = n - 1;

    while (l >= 0 && A[l] <= A[l + 1])
      l--;
    if (l < 0)
      return A;
    while (A[r] >= A[l] || A[r] == A[r - 1])
      r--;
    swap(A[l], A[r]);

    return A;
  }
};
